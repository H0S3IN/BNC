#include "../include/BNC.hpp"

Number Sum(Number &num1, Number &num2){
  
    std::string result{""};
    Number *num_higher_p; 
    Number *num_lower_p;
    if(num2 >= num1){
        num_higher_p = new Number(num2);  // compairing
        num_lower_p = new Number(num1);
    }
    else{
        num_higher_p = new Number(num1);  // compairing
        num_lower_p = new Number(num2);
    }
    
    uint16_t carr{0};

    while(num_lower_p->is_pos_higher_than_zero()){
      
        uint16_t char_num_higher=0,char_num_lower=0;
      
        if(num_lower_p->get_num() == "\0"){
              return *num_higher_p;
        }
        else{
            char char2 = num_lower_p->get_char_num();
            char_num_lower = char2 - 48; //char to int
            char char1 = num_higher_p->get_char_num();
            char_num_higher = char1 - 48;

        }
        uint16_t res = char_num_higher + char_num_lower + carr;
        carr = res / 10; //get and set first digit or carry

        result = std::to_string(res%10) + result;

        num_lower_p->dec_pos();
        num_higher_p->dec_pos();
    }
    size_t diff = num_higher_p->get_num().size() - num_lower_p->get_num().size();
    if(diff > 0){
        std::string high_value = num_higher_p->get_num().substr(0,diff);
        high_value[high_value.size()-1] = (high_value[high_value.size()-1] + carr);
        result = (high_value + result);
    }
    else if(diff==0){
        result = std::to_string(carr) + result;
    }
    else{}
    

    
    
    return Number(result);
}

