#include <iostream>

using namespace std;

struct config {
    unsigned discrete_video: 1;
    unsigned dualcore_processor: 1;
    unsigned touch_screen: 1;
    unsigned atx_box: 1;
} computer;

int main()
{
    computer.atx_box = 1;
    computer.discrete_video = 1;
    computer.dualcore_processor = 0;
    computer.touch_screen = 0;

    cout << "Корпус и плата ATX: " << computer.atx_box << endl;
    cout << "Дискретная видеокарта: " << computer.discrete_video << endl;
    cout << "Двухядерный процессор: " << computer.dualcore_processor << endl;
    cout << "Сернсорный экран: " << computer.touch_screen << endl;
    return 0;
}
