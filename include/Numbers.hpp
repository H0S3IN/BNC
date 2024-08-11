#ifndef _NUMBERS_H_
#define _NUMBERS_H_
#include <string>
#include <cstdint>

class Number{
private:
    std::string num_str;
    long long pos;
    uint8_t char_num;
    constexpr void pre_proc();
public:
    void set_num(std::string input);
    std::string get_num() const;
    size_t get_lenght() const;
    uint8_t get_char_num();
    size_t get_pos();
    bool is_pos_higher_than_zero();
    void dec_pos();
    void replace(Number &input);
    Number(std::string input);
    Number();
    void operator=(Number &input);
    bool operator>=(Number &input) const;

};

#endif
