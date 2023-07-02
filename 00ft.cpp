#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>


void print_alphabet() {
	char a;
	for (a = 97; a <= 123; a++) {
		std::cout << a << " ";
	}
}


void Camb() {
	int i;
	for (i = 0; i <= 7; i++) {
		int j = i + 1;
		for (j; j <= 8; j++) {
			int k = j + 1;
			for (k; k <= 9; k++) {
				std::cout << i <<  j << k << "\n";
			}
		}
	}
}



int str_len(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}

	return i;

}

int* ft_rev_int_tab(int* tab, int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - j - 1; i++) {
			int k = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = k;
		}
	}
	return tab;
}

int* min(int* tab, int size, int j) {
	int resultarray[2] = {tab[j], j};
	for (int i = j; i < size; i++) {
		if (tab[i] < resultarray[0]) {
			resultarray[0] = tab[i];
			resultarray[1] = i;
		}
	}
	int* result = resultarray;
	return result;
}

int* sort(int* tab, int size) {
	for (int i = 0; i < size; i++) {
		int* result = min(tab, size, i);
		int l = tab[i];
		tab[i] = result[0];
		tab[result[1]] = l;
	}

	return tab;
}

char* cpstr(char* dis, char* src) {
	for (int i = 0; i < str_len(src); i++) {
		dis[i] = src[i];
	}

	return dis;
}

char* cpnstr(char* dis, char* src, int n) {
	for (int i = 0; i < str_len(src); i++) {
		if (i < n) {
			dis[i] = src[i];
		}
		else {
			dis[i] = *"";
		}
	}

	return dis;
}


int is_alpha(char* str) {
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122){
			return 0;
		}
	}

	return 1;
}

char* to_upper(char* str) {
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			str[i] = int(str[i]) - 32;
		}
	}

	return str;
}

char* capital(char* str) {
	int l = 0;
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
			if (str[i - l] >= 97 && str[i - l] <= 122) {
				str[i - l] = int(str[i - l]) - 32;
			}
			for (int j = i - l + 1; j < i; j++) {
				if (str[j] >= 65 && str[j] <= 90) {
					str[j] = int(str[j]) + 32;
				}
			}
			l = -1;
		}
		l++;
	}

	return str;
}

int strcamp_ft(char* str_01, char* str_02) {
	for (int i = 0; i < str_len(str_01); i++) {
		if (str_01[i] != str_02[i]) {
			if (str_01[i] > str_02[i]) {
				return 1;
			}
			else {
				return -1;
			}
		}
	}

	return 0;
}

char* catstr_ft(char* dis, char* src) {
	int l = str_len(dis);
	for (int i = 0; i < str_len(src); i++) {
		dis[l + i] = src[i];
	}

	return dis;
}


char* strstr_ft(char* str, char* substr) {
	int len = str_len(substr);
	char last_char = substr[len - 1];
	int count = 0;
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] == last_char) {
			for (int j = 0; j < len; j++) {
				count++;
				if (str[i - len + j + 1] != substr[j]) {
					break;
				}
			}

			if (count == len) {
				return (str + i - len + 1);
			}
			count = 0;
		}
	}

	return nullptr;

	
}

int ft_recursive_fact(int a) {
	if (a > 1) {
		a = a * ft_recursive_fact(a - 1);
	}
	return a;
}

int ft_power_recursion(int nb, int power) {
	if (power > 1) {
		nb = nb * ft_power_recursion(nb, power - 1);
	}

	return nb;
}

int ft_fibonacci(int index) {
	int F;
	if (index == 0) {
		F = 0;
	}
	else if (index == 1) {
		F = 1;
	}
	else {
		F = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}

	return F;
}

float ft_sqrt_heron(float s0, int index) {
	float suite;
	if (index == 0) {
		suite = s0;
	}
	else {
		suite = (1.0 / 2.0) * (ft_sqrt_heron(s0, index - 1) + s0 / ft_sqrt_heron(s0, index - 1));
	}

	return suite;
}

float heron_method(float x, float guess, float epsilon) {
	float nextguess = 0.5 * (guess + x / guess);
	if (fabs(nextguess - guess) <= epsilon) {
		return nextguess;
	}

	heron_method(x, nextguess, epsilon);
}

float ft_sqrt(float x) {
	return heron_method(x, x, 1.0 / (ft_power_recursion(10, 3)));
}

int is_prime(int nb) {
	for (int i = 2; i < nb; i++) {
		if (nb % i == 0) {
			return -1;
		}
	}

	return 1;
}

int next_prime(int nb){
	if (is_prime(nb) == -1) {
		next_prime(nb + 1);
	}
	else {
		return nb;
	}
}

char* ft_strdup(char* src) {
	char* New;
	New = (char*)malloc((str_len(src) + 1) * sizeof(char));
	for (int i = 0; i < str_len(src); i++) {
		New[i] = src[i];
	}
	New[str_len(src)] = '\0';
	return New;

}


int* ft_range(int min, int max) {

	int* result;
	result = (int*)malloc((max - min + 1) * sizeof(int));
	for (int i = 0; i < max - min + 1; i++) {
		result[i] = min + i;
	}

	return result;
}


char* ft_strjoin(int size, char** strs, char* sep) {
	int len = 0;
	char* result;
	for (int i = 0; i < size; i++) {
		len += str_len(strs[i]);
	}
	
	len += (size - 1) * str_len(sep);
	result = (char*)malloc((len + 1) * sizeof(char));
	int count = 0;
	for (int j = 0; j < size; j++) {
		for (int l = 0; l < str_len(strs[j]); l++) {
			result[count] = strs[j][l];
			count++;
		}

		for (int k = 0; k < str_len(sep); k++) {
			result[count] = sep[k];
			count++;
		}
	}

	result[len + 1] = '\0';

	return result;
	
}


int string_count(char* str, char* charset) {
	int result = 0;
	int count = 0;
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] == charset[str_len(charset) - 1]) {
			for (int j = 0; j < str_len(charset); j++) {
				count++;
				if (str[i - str_len(charset) + j + 1] != charset[j]) {
					break;
				}
			}

			if (count == str_len(charset)) {
				result++;
			}

			count = 0;
		}
	}

	return result+1;
}



char** ft_split(char* str, char* charset) {
	int size = string_count(str, charset);
	char** result = (char**)malloc((size+1) * sizeof(char*));
	int l = 0;
	int count = 0;
	int z = 0;
	int a = 0;
	for (int i = 0; i < str_len(str); i++) {
		if (str[i] == charset[str_len(charset) - 1]) {
			for (int j = 0; j < str_len(charset); j++) {
				count++;
				if (str[i - str_len(charset) + j + 1] != charset[j]) {
					break;
				}
			}

			if (count == str_len(charset)) {
				result[l] = (char*)malloc((i - str_len(charset) - z + 1)*sizeof(char));
				for (int k = z; k < i - str_len(charset) + 1; k++) {
					result[l][a] = str[k];
					a++;
				}
				result[l][i - str_len(charset) - z + 1] = '\0';
				z = i;
				l++;
				a = 0;
			}

			count = 0;
		}
	}

	result[size] = 0;
	return result;

}

void  ft_foreach(int* tab, int size, void(*f)(int)) {
	for (int i = 0; i < size; i++) {
		f(tab[i]);
	}
}

int* ft_map(int* tab, int size, int(*f)(int)) {
	int* result = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		result[i] = f(tab[i]);
	}

	return result;
}

int compare(int a, int b) {
	if (a < b) {
		return -1;
	}
	else if (a == b) {
		return 0;
	}
	else {
		return 1;
	}
}

int ft_is_sort(int* tab, int size, int(*f)(int, int)) {
	for (int i = 0; i < size - 1; i++) {
		if (f(tab[i], tab[i + 1]) > 0) {
			return 0;
		}
	}

	return 1;
}










