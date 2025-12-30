#include <iostream>

#include "Dog.cpp"

int main() {

    Dog dog1("西卡", 5);
    Dog dog2("西米露", 1);

    // @todo 众狗之神需要统计现在有几只小狗
    std::cout << "There're " << "dogs here." << std::endl;

    // @todo 西卡给西米露过生日
    dog1.age += 1; // 对，对吗？好粗暴，西卡生日蛋糕都没吃，生日就过去了

    // @todo 西米露要和西卡比大小
    std::cout << "Am I oldder than you? True or false?" << std::endl;

    // @todo 为了报复西米露不给自己过生日，西卡决定给西米露过一百个生日

    // @todo 现在西卡和西米露谁大？
    std::cout << "The oldest dog is " << " now." << std::endl;

    // @todo 众狗之神决定给所有小狗过生日
    Dog::have_birthday_to_all();

    return 0;
}