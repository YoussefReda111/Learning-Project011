#pragma once

#include <iostream>
#include <string>
#include "cls_date.h"

using namespace std;

class cls_utility
{
public:
    enum en_char_type {
        small_letter, capital_letter,
        digit, mix_chars, special_character
    };

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int random_number(int from, int to)
    {
        int rand_num = rand() % (to - from + 1) + from;
        return rand_num;
    }

    static char get_random_character(en_char_type char_type)
    {
        if (char_type == mix_chars)
        {
            char_type = (en_char_type)random_number(1, 3);
        }
        switch (char_type)
        {
        case en_char_type::small_letter:
        {
            return char(random_number(97, 122));
            break;
        }
        case en_char_type::capital_letter:
        {
            return char(random_number(65, 90));
            break;
        }
        case en_char_type::special_character:
        {
            return char(random_number(33, 47));
            break;
        }
        case en_char_type::digit:
        {
            return char(random_number(48, 57));
            break;
        }
    defualt:
        {
            return char(random_number(65, 90));
            break;
        }
        }
    }

    static string generate_word(en_char_type char_type, short length)
    {
        string word;
        for (int i = 1; i <= length; i++)
        {
            word = word + get_random_character(char_type);
        }
        return word;
    }

    static string generate_key(en_char_type char_type = capital_letter)
    {
        string key = "";
        key = generate_word(char_type, 4) + "-";
        key = key + generate_word(char_type, 4) + "-";
        key = key + generate_word(char_type, 4) + "-";
        key = key + generate_word(char_type, 4);
        return key;
    }

    static void generate_keys(short number_of_keys, en_char_type char_type)
    {
        for (int i = 1; i <= number_of_keys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << generate_key(char_type) << endl;
        }
    }

    static void fill_array_with_random_numbers(int arr[100], int arr_length, int from, int to)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = random_number(from, to);
    }

    static void fill_array_with_random_words(string arr[100], int arr_length, en_char_type char_type, short word_length)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = generate_word(char_type, word_length);
    }

    static void fill_array_with_random_keys(string arr[100], int arr_length, en_char_type char_type)
    {
        for (int i = 0; i < arr_length; i++)
            arr[i] = generate_key(char_type);
    }

    static void swap(int& A, int& B)
    {
        int temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void swap(double& A, double& B)
    {
        double temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void swap(bool& A, bool& B)
    {
        bool temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void swap(char& A, char& B)
    {
        char temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void swap(string& A, string& B)
    {
        string temp;
        temp = A;
        A = B;
        B = temp;
    }

    static void swap(cls_date& A, cls_date& B)
    {
        cls_date::swap_dates(A, B);
    }

    static void shuffle_array(int arr[100], int arr_length)
    {
        for (int i = 0; i < arr_length; i++)
        {
            swap(arr[random_number(1, arr_length) - 1], arr[random_number(1, arr_length) - 1]);
        }
    }

    static void shuffle_array(string arr[100], int arr_length)
    {
        for (int i = 0; i < arr_length; i++)
        {
            swap(arr[random_number(1, arr_length) - 1], arr[random_number(1, arr_length) - 1]);
        }
    }

    static string tabs(short number_of_tabs)
    {
        string t = "";
        for (int i = 1; i < number_of_tabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string encrypt_text(string text, short encryption_key)
    {
        for (int i = 0; i <= text.length(); i++)
        {
            text[i] = char((int)text[i] + encryption_key);
        }
        return text;
    }

    static string decrypt_text(string text, short encryption_key)
    {
        for (int i = 0; i <= text.length(); i++)
        {
            text[i] = char((int)text[i] - encryption_key);
        }
        return text;
    }
};