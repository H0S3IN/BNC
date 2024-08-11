#include "../include/Numbers.hpp"
//#include <cctype>
//#include <algorithm>

void Number::set_num(std::string input){
    num_str = input;
    pre_proc();
    //it = num_str.end();
    //it--;
    //char_num = *it;
    if(pos>0)
        pos = num_str.size() - 1;
    else{}
    char_num = num_str[pos];
}
std::string Number::get_num() const{
    return num_str;
}
uint8_t Number::get_char_num(){
    return char_num; 
}
// std::string::iterator Number::get_it(){
//     return it;
// }
size_t Number::get_pos(){
    return pos;
}
// void Number::dec_it(){
//     it--;
//     char_num = *it;
// }
void Number::dec_pos(){
    if(pos>0){
        pos--;
        char_num = num_str[pos];
    }
    else{
        pos--;
    }
    
}
bool Number::is_pos_higher_than_zero(){
    return pos >= 0;
}
size_t Number::get_lenght() const{
    return get_num().length();
}

void Number::operator=(Number &input){
    this->set_num(input.get_num());
}
bool Number::operator>=(Number &input) const{
    
    bool flag = true;
    if(this->get_lenght() < input.get_lenght()){
        return false;
    }
    else if(this->get_lenght() == input.get_lenght()){
        for(size_t size=0;size < this->get_lenght(); size++){
            if(this->get_num().at(size) == input.get_num().at(size))
                continue;
            else if(this->get_num().at(size) < input.get_num().at(size)){
                return false;
                }
            else
                return true;
        
        }

    }
    else{
        return true;
    }
    return true;
}

Number::Number(std::string input){
    set_num(input);
}
Number::Number(){
    set_num("");
}

bool is_number(std::string i){
    for(char c:i){
        if(c<48 || c>57)
            return false;
    }
    return true;
}
constexpr void Number::pre_proc(){
    if(!is_number(this->get_num())){
        this->set_num("0");
    }
    
    else{
        for(auto it = num_str.begin(); it != num_str.end() ;){
        
            if(*it == '0'){
                if(*(it+1) =='0'){
                    num_str.erase(it);
                    num_str.erase(it);
                }
                else{
                    num_str.erase(it);
                    break;
                }
            }
            else
                break;
            
    }

    }
}

void Number::replace(Number &input){
    Number *temp = new Number;
    temp->set_num(this->get_num());
    this->set_num(input.get_num());
    input.set_num(temp->get_num());
    delete temp;
}

// void Number::pre_proc(Number &input){
//     bool flag = true;
//     if(this->get_lenght() < input.get_lenght()){
//         this->replace(input);
//         flag = false;
//     }
//     else if(this->get_lenght() == input.get_lenght()){
//         for(size_t size=0;size < this->get_lenght(); size++){
//             if(this->get_num().at(size) == input.get_num().at(size))
//                 continue;
//             else if(this->get_num().at(size) < input.get_num().at(size)){
//                 this->replace(input);
//                 flag = false;
//                 break;
//                 }
//             else
//                 break;
        
//         }

//     }
//     else{
//         flag = false;
//     }

//     // if(flag == false){
//     //     std::string zero{""};
//     //     for(size_t i = this->get_lenght() - input.get_lenght() ; i>0 ; i--){
//     //         zero+="0";
//     //         }
//     // input.set_num(zero+input.get_num());
//     // }
    
// }

