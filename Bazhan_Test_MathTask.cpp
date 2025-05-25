#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

#include "Bazhan_MathTask.h"

using namespace cute;

void testcalculateArea() {
    int actual = calculateArea(5, 6);
    ASSERT_EQUAL(30, actual);
}

void test_input_validation_Empty() {
    string str = "";
    bool expected = false;
    bool actual = inputValidation(str);  
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
    string str = "a";
    bool expected = false;
    bool actual = inputValidation(str);  
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_DigitLetterValue() {
    string str = "5a";
    bool expected = false;
    bool actual = inputValidation(str);  
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue() {
    string str = "-5";
    bool expected = false;
    bool actual = inputValidation(str);  
    ASSERT_EQUAL(expected, actual);
}

void test_input_validation() {
    // Пустая строка
    ASSERT_EQUAL(false, inputValidation(""));
    
    // Буквенные значения
    ASSERT_EQUAL(false, inputValidation("a"));
    ASSERT_EQUAL(false, inputValidation("abc"));
    
    // Цифро-буквенные комбинации
    ASSERT_EQUAL(false, inputValidation("5a"));
    ASSERT_EQUAL(false, inputValidation("a5"));
    ASSERT_EQUAL(false, inputValidation("1a2b3c"));
    
    // Отрицательные числа (теперь должны возвращать false)
    ASSERT_EQUAL(false, inputValidation("-5"));
    ASSERT_EQUAL(false, inputValidation("-"));
    
    // Корректные положительные числа
    ASSERT_EQUAL(true, inputValidation("0"));
    ASSERT_EQUAL(true, inputValidation("123"));
    ASSERT_EQUAL(true, inputValidation("100500"));
}

int main() {
    suite s;
    s.push_back(CUTE(testcalculateArea));
    s.push_back(CUTE(test_input_validation_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));
    s.push_back(CUTE(test_input_validation)); 
    ide_listener<> listener;
    makeRunner(listener)(s, "All Rectangle Tests");
    return 0;
}
