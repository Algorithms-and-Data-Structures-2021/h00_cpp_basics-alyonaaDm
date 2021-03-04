#include <iostream>   // cout
#include <algorithm>  // copy, fill
#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs != nullptr && rhs != nullptr) {
        int k = *lhs;
        *lhs = *rhs;
        *rhs = k;
    }

}
// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows <= 0 || num_cols <= 0) {
        return nullptr;
    }
    int **array_2d = new int *[num_rows];
    for (int row_index = 0; row_index < num_rows; ++row_index) {
        array_2d[row_index] = new int[num_cols];
    }
    for (int row_index = 0; row_index < num_rows; row_index++) {
        for (int column_index = 0; column_index < num_cols; column_index++) {
            array_2d[row_index][column_index] = init_value;
        }
    }
    return array_2d;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (num_rows < 0 || num_cols < 0 || arr_2d_source == nullptr || arr_2d_target == nullptr) {
        return false;
    }
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            arr_2d_target[i][j] = arr_2d_source[i][j];
        }
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    int n = arr.size() - 1;
    for (int i = 0; i < arr.size() / 2; ++i) {
        int k;
        k = arr[i];
        arr[i] = arr[n];
        arr[n] = k;
        n--;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin != nullptr || arr_end != nullptr) {
        while (arr_begin < arr_end) {
            swap_args(arr_begin, arr_end);
            arr_begin++;
            arr_end--;
        }
    }

}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr != nullptr && size > 0) {
        int *maxi = &arr[0];

        for (int i = 0; i < size; i++) {
            if (arr[i] > *maxi) {
                *maxi = arr[i];
            }
        }
        return maxi;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> a;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {
            a.push_back(arr[i]);
        }
    }
    return a;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> a;
    vector<int> unic;
    for (int i = 0; i < arr_a.size(); ++i) {
        for (int j = 0; j < arr_b.size(); ++j) {
            if (arr_a[i] == arr_b[j]) {
                bool check = true;
                for (int k = 0; k < unic.size(); ++k) {
                    if (unic[k] == i) {
                        check = false;
                    }
                }
                if (check) {
                    a.push_back(arr_a[i]);
                    unic.push_back(i);
                }
            }
        }
    }
    return a;

}
