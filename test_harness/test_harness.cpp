
#include <iostream>
#include <time.h>

// All functions copied from Gunteroth

// original, naive remove_ctrl()
std::string remove_ctrl(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}

// remove_ctrl() with operator replaced by mutating assignment
std::string remove_ctrl_mutating(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
std::string remove_ctrl_mutating_it(std::string s) {
    std::string result;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

std::string remove_ctrl_mutating_it_end(std::string s) {
    std::string result;
    for (auto it = s.begin(), end = s.end();it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

// remove_ctrl_mutating() with space reserved in result
std::string remove_ctrl_reserve(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}
std::string remove_ctrl_reserve_it(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (auto it = s.begin(), end = s.end();it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

// remove_ctrl_reserve() with reference arg instead of value arg
std::string remove_ctrl_refs(std::string const& s) {
    std::string result;
    result.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}

// remove_ctrl_reserve() with reference arg instead of value arg
std::string remove_ctrl_refs_it(std::string const& s) {
    std::string result;
    result.reserve(s.length());
    for (auto it = s.begin(), end = s.end();it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
    return result;
}

// remove_ctrl_refs() with reference return value
void remove_ctrl_ref_result(
    std::string& result,
    std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
}

// remove_ctrl_ref_ret with iterators
void remove_ctrl_ref_result_it(
    std::string& result,
    std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (auto it = s.begin(), end = s.end();it != end; ++it) {
        if (*it >= 0x20)
            result += *it;
    }
}

// remove_ctrl_ref_result() done with buffers instead of strings
void remove_ctrl_cstrings(char* destp, char const* sourcep, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (sourcep[i] >= 0x20)
            *destp++ = sourcep[i];
    }
    *destp = 0;
}

//  copy whole substrings to reduce allocations
std::string remove_ctrl_block(std::string s) {
    std::string result;
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20) break;
        }
        result = result + s.substr(b, i - b);
    }
    return result;
}

// remove_ctrl_block() with mutating concatenation, reserved size
std::string remove_ctrl_block_mutate(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20) break;
        }
        result += s.substr(b, i - b);
    }
    return result;
}

std::string remove_ctrl_block_append(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b = 0, i = b; b < s.length(); b = i + 1) {
        for (i = b; i < s.length(); ++i) {
            if (s[i] < 0x20) break;
        }
        result.append(s, b, i - b);
    }
    return result;
}

std::string remove_ctrl_block_append_it(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (auto b = s.begin(), i = b; b != s.end(); b = i + 1) {
        for (i = b; i != s.end(); ++i) {
            if (*i < 0x20) break;
        }
        result.append(b, i);
    }
    return result;
}

std::string remove_ctrl_block_append_cache(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20) break;
        }
        result.append(s, b, i - b);
    }
    return result;
}

std::string remove_ctrl_block_append_cache_it(std::string s) {
    std::string result;
    result.reserve(s.length());
    for (auto b = s.begin(), i = s.begin(), e = s.end(); b != e; b = i + 1) {
        for (i = b; i != e; ++i) {
            if (*i < 0x20) break;
        }
        result.append(b, i);
    }
    return result;
}

// remove_ctrl_block_mutate() with reference arg
std::string remove_ctrl_blocks(std::string const& s) {
    std::string result;
    result.reserve(s.length());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20) break;
        }
        result.append(s, b, i - b);
    }
    return result;
}
//  remove_ctrl_blocks() with reference return value
void remove_ctrl_block_ret(std::string& result, std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (size_t b = 0, i = b, e = s.length(); b < e; b = i + 1) {
        for (i = b; i < e; ++i) {
            if (s[i] < 0x20) break;
        }
        result.append(s, b, i - b);
    }
}

void remove_ctrl_block_ret_it(std::string& result, std::string const& s) {
    result.clear();
    result.reserve(s.length());
    for (auto b = s.begin(), i = b, e = s.end(); b != e; b = i + 1) {
        for (i = b; i != e; ++i) {
            if (*i < 0x20) break;
        }
        result.append(b, i);
    }
}

//  cleverly reduce the size of a string so it doesn't have to be reallocated
std::string remove_ctrl_erase(std::string s) {
    for (size_t i = 0; i < s.length(); )
        if (s[i] < 0x20)
            s.erase(i, 1);
        else ++i;
    return s;
}
std::string remove_ctrl_erase_it(std::string s) {
    for (auto i = s.begin(); i != s.end(); )
        if (*i < 0x20)
            s.erase(i);
        else ++i;
    return s;
}

int test_func(int test_no, unsigned long iteration_multiplier) {
    typedef unsigned counter_t;
    counter_t iterations = 1000 * iteration_multiplier;
    clock_t t;
    std::string s("\07Mustan kissan paksut\07 posket. Appilan pappilan apupapin papupata pankolla kiehuu ja kuohuu. \07");
    std::string control("Mustan kissan paksut posket. Appilan pappilan apupapin papupata pankolla kiehuu ja kuohuu. ");
    std::string result;
    std::string name;
    float time;

    s = s + s + s;
    control = control + control + control;

    bool rc = true;

    switch (test_no) {
    default: return -1;
    case 0:
        std::cout << s.length() << " character argument to remove_ctrl()" << std::endl;
        std::cout << iterations << " iterations" << std::endl;

        result = remove_ctrl(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_mutating(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_mutating_it(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_reserve(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_reserve_it(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_refs(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_refs_it(s);
        rc &= (result.compare(control) == 0);
        remove_ctrl_ref_result(result, s);
        rc &= (result.compare(control) == 0);
        remove_ctrl_ref_result_it(result, s);
        rc &= (result.compare(control) == 0);
        {
            char a[1000];
            memset(a, 0, sizeof(a));
            remove_ctrl_cstrings(a, s.data(), s.length());
            rc &= (strcmp(a, control.data()) == 0);
        }
        result = remove_ctrl_block(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_block_mutate(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_block_append(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_block_append_it(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_block_append_cache(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_block_append_cache_it(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_blocks(s);
        rc &= (result.compare(control) == 0);
        remove_ctrl_block_ret(result, s);
        rc &= (result.compare(control) == 0);
        remove_ctrl_block_ret(result, s);
        rc &= (result.compare(control) == 0);
        remove_ctrl_block_ret_it(result, s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_erase(s);
        rc &= (result.compare(control) == 0);
        result = remove_ctrl_erase_it(s);
        rc &= (result.compare(control) == 0);
        break;
    case 1:
        t = clock();
        name = "remove_ctrl()";

        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl(s);

        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 2:
        t = clock();
        name = "remove_ctrl_mutating()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_mutating(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_mutating_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_mutating_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_mutating_it_end()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_mutating_it_end(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 3:
        t = clock();
        name = "remove_ctrl_reserve()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_reserve(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_reserve_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_reserve_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;
    
    case 4:
        t = clock();
        name = "remove_ctrl_refs()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_refs(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_refs_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_refs_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;
   
    case 5:
        t = clock();
        name = "remove_ctrl_ref_result()";
        for (counter_t i = 0; i < iterations; ++i)
            remove_ctrl_ref_result(result, s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_ref_result_it()";
        for (counter_t i = 0; i < iterations; ++i)
            remove_ctrl_ref_result_it(result, s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 6:
        t = clock();
        name = "remove_ctrl_cstrings()";

        for (counter_t i = 0; i < iterations; ++i) {
            char a[1000];
            remove_ctrl_cstrings(a, s.data(), s.length());
        }

        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 7:
        t = clock();
        name = "remove_ctrl_block()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 8:
        t = clock();
        name = "remove_ctrl_block_mutate()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block_mutate(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_block_append()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block_append(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_block_append_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block_append_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_block_append_cache()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block_append_cache(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_block_append_cache_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_block_append_cache_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 9:
        t = clock();
        name = "remove_ctrl_blocks()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_blocks(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 10:
        t = clock();
        name = "remove_ctrl_block_ret()";
        for (counter_t i = 0; i < iterations; ++i)
            remove_ctrl_block_ret(result, s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_block_ret_it()";
        for (counter_t i = 0; i < iterations; ++i)
            remove_ctrl_block_ret_it(result, s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;

    case 11:
        t = clock();
        name = "remove_ctrl_erase()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_erase(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";

        t = clock();
        name = "remove_ctrl_erase_it()";
        for (counter_t i = 0; i < iterations; ++i)
            result = remove_ctrl_erase_it(s);
        t = clock() - t;
        time = float(t) / CLOCKS_PER_SEC;
        std::cout << name << "," << time << "," << time/(float)iterations << "\n";
        break;
    }

    return rc ? 1 : 0;
}

void test_suite(unsigned long iteration_multiplier) {
    int value;
    for (int i = 0; ; i++) {
        value = test_func(i, iteration_multiplier);
        if (value != 1) break;
    }
    
}

int main()
{
    test_suite(10); // n * 1000 iterations on tests
}

