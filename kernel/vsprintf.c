#include <smart/vsprintf.h>
#include <defs.h>


#define MAX_BUF_SIZE 512 
#define NUM_BUF 80

static char *int_to_string(char *buf, int n){
	int pos = NUM_BUF;
	int negative = 0;

	if(n < 0){
		negative = 1;
		n = -n;
	}

	buf[--pos] = 0;

	while(n >= 10) {
		int digit = n % 10;
		n /= 10;
		buf[--pos] = digit + '0';
	}
	buf[--pos] = n + '0';

	if(negative)
		buf[--pos] = '-';

	return &buf[pos];
}

static char *long_to_string(char *buf, unsigned long n){
	int pos = NUM_BUF;

	buf[--pos] = 0;

	while(n >= 10) {
		int digit = n % 10;
		n /= 10;
		buf[--pos] = digit + '0';
	}

	buf[--pos] = n + '0';

	return &buf[pos];
}

static char *long_to_hexstring(char *buf, unsigned long n){
	int pos = NUM_BUF;
	char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F'};

	buf[--pos] = 0;

	while(n >= 16) {
		int digit = n % 16;
		n /= 16;
		buf[--pos] = table[digit];
	}
	buf[--pos] = table[n];

	return &buf[pos];
}

// void printf(const char *format, ...) {
// 	va_list val;
// 	char str[MAX_BUF_SIZE] = {0};
// 	int printed = 0;

// 	va_start(val, format);
// 	vsprintf(str, format, val);
// 	va_end(val);

// 	printk(str);
// 	// while(str[printed]) {
// 	// 	print_to_screen(str[printed]);
// 	// 	++printed;
// 	// }

// 	return;
// }

int vsprintf(char *str, const char *fmt, va_list ap){
	char c;
	int n;
	unsigned long long ull;
	char uc;
	const char *s;
	size_t idx = 0;
	size_t j;
	char buf[NUM_BUF];

	for(;;) {
		while((c = *fmt++) != 0){
			if(c == '%')
				break;
			str[idx++] = c;
		}

		if(c == 0)
			break;

		c = *fmt++;
		if(c == 0)
			break;

		/* we do a naive parse, only %d, %s, %c, %lx is accept */
		if(c == 'c'){
			uc = va_arg(ap, unsigned int);
			str[idx++] = uc;
		} else if(c == 's'){
			s = va_arg(ap, const char *);
			if(s == 0)
				s = "<null>";
			j = 0;
			while(s[j] != 0){
				str[idx++] = s[j++];
			}
		} else if(c == 'd'){
			n = va_arg(ap, int);
			s = int_to_string(buf, n);
			j = 0;
			while(s[j] != 0){
				str[idx++] = s[j++];
			}
		} else if(c == 'x'){
			ull = va_arg(ap, uint64_t);
			s = long_to_hexstring(buf, ull);
			j = 0;
			while(s[j] != 0){
				str[idx++] = s[j++];
			}
		} else if(c == 'p'){
			str[idx++] = '0';
			str[idx++] = 'x';
			ull = va_arg(ap, uint64_t);
			s = long_to_hexstring(buf, ull);
			j = 0;
			while(s[j] != 0){
				str[idx++] = s[j++];
			}
		} else if(c == 'l'){
			c = *fmt++;
			if(c == 'x'){
				ull = va_arg(ap, unsigned long long);
				s = long_to_hexstring(buf, ull);
				j = 0;
				while(s[j] != 0){
					str[idx++] = s[j++];
				}
			} else if(c == 'u'){
				ull = va_arg(ap, unsigned long long);
				s = long_to_string(buf, ull);
				j = 0;
				while(s[j] != 0){
					str[idx++] = s[j++];
				}
			} else {
				str[idx++] = '%';
				str[idx++] = 'l';
				str[idx++] = c;
			}
		} else {
			str[idx++] = '%';
			str[idx++] = c;
		}
	}

	return idx;
}

