#include <iostream>

#include "Dog.cpp"

int main() {

    Dog dog1("西卡", 5);
    Dog dog2("西米露", 1);

    // @todo 众狗之神需要统计现在有几只小狗
    std::cout << "There're " << Dog::dog_number << " dogs here." << std::endl;

    // @todo 西米露给西卡过生日
    dog2.have_birthday(dog1);
    //dog1.age += 1; // 对，对吗？好粗暴，西卡生日蛋糕都没吃，生日就过去了

    // @todo 西米露要和西卡比大小
    std::cout << "Am I oldder than you? True or false?" << std::endl;
    std::cout << dog2.older_than(dog1) << std::endl;

    // @todo 为了报复西米露不给自己过生日，西卡决定给西米露过一百个生日
    for (int i = 0; i < 100; i++)
    {
        dog1.have_birthday(dog2);
    }

    // @todo 现在西卡和西米露谁大？
    std::cout << "The oldest dog is " << Dog::older_dog(dog1, dog2).name << " now." << std::endl;

    // @todo 众狗之神决定给所有小狗过生日
    //dog1.have_birthday(dog2);
    //dog2.have_birthday(dog1);
    Dog::have_birthday_to_all();

    return 0;
}