#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief 每一个对象都是一只可爱的小狗
 */
class Dog
{
public:
    // =======众狗之神有什么=======
    inline static int dog_number = 0;// 现在一共有几只小狗？小狗不该操心这个，这是众狗之神管的事情，所以不在小狗对象中，一开始有0只
    inline static std::vector<Dog*> dog_list;

    // =======每一只小狗对象有些什么=======
    std::string name;// 小狗的名字
    int age;// 小狗的年龄

    /**
     * 小狗类的构造函数，每一只小狗对象都是从这里产生的
     */
    Dog(std::string name, int age) { // 创建一只小狗需要知道它的年龄和名字
        this->name = name;
        this->age = age;
        std::cout << "My name is " << name << ", I'm " << age << " years old." << std::endl;
        // @todo 还需要干什么吗？这只小狗好像还不在众狗之神的花名册里
        dog_number += 1;
        dog_list.push_back(this);
    }
    ~Dog() { // 消灭小狗时要做什么，如果小狗没了，需要开追悼会，好吧，有点地狱，好在只是赛博小狗
        std::cout << "Goodbye, " << name << "." << std::endl;
        // @todo 少了点什么
        // 从列表中移除这只小狗
        auto it = std::find(dog_list.begin(), dog_list.end(), this);
        if (it != dog_list.end()) {
            dog_list.erase(it);
        }
        dog_number -= 1;
    }

    /**
     * @brief 给这只小狗过生日，需要干些什么呢？
     */
    void have_birthday() {
        std::cout << name << " is eating birthday cake ..." << std::endl;
        // @todo
        age +=1;
        std::cout << name << " is " << age << " years old now." << std::endl;
        
    }

    /**
     * @brief 同样是过生日，但这次是给其他小狗过
     */
    void have_birthday(Dog& other) { // 这里对吗？哎呀，我好像不小心把该过生日的小狗复制了一份，它现在变成克隆狗了，这可不好
        std::cout << "Happy Birthday! " << other.name << "." << std::endl;
        // @todo 这里好像少了点什么？
        other.have_birthday();
    }

    /**
     * @brief 比年龄大小，这只小狗想要比比它和同伴谁更大一些？
     * @return 如果这只狗更大，返回true，反之，返回false
     */
    bool older_than(Dog& other) {
        return ( (this->age) > other.age );
    }

    /**
     * @brief 众狗之神啊！你来裁决一下我面前的这两只狗谁大谁小吧！
     */
    static Dog& older_dog(Dog& dog1, Dog& dog2) { // 哎呀，我好像又克隆了一只小狗，年龄大的小狗会被克隆一份，怎么回事呢？
        // @todo
        //std::cout << dog1.name << " is " << dog1.age << " years old now." << std::endl;
        //std::cout << dog2.name << " is " << dog2.age << " years old now." << std::endl;
        if (dog1.age > dog2.age)
        {
            return dog1;
        }else if (dog2.age > dog1.age)
        {
            return dog2;
        }else
        {
            std::cout << "Gougou is a bad dog." << std::endl;
            return dog1;
        }
    }

    /**
     * @brief 挑战：众狗之神想要给所有小狗过生日，你能帮帮它吗？
     * 提示：可能需要给众狗之神一个花名册，让它可以随时找到所有小狗，
     * <vector>好像挺合适的，std::vector::push_back()方法可以在数组后面添加元素哦
     * 注意：std::vector<你要在数组里放什么东西> 这么去用哦
     */
    static void have_birthday_to_all() {
        for (int i = 0; i < dog_number-1; i++)
        {
            dog_list[i] -> have_birthday(*dog_list[i+1]);
        }
        dog_list[dog_number-1] -> have_birthday(*dog_list[0]);
    }
};