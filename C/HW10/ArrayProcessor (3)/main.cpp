#include "header.h"

int main()
{
    cout << "��������� ��� ��������� �������" << endl;
    cout << "������� ����������� ������, ��������� �������� ��� ���." << endl;

    int const SIZE = 20;
    int array1[SIZE];
    int position;

    randomizer(array1,SIZE); //������� ����������� ������ ���������� �������
    printer(array1,SIZE); //������� ������ �������

    cout << "� ������ ���������� �� ������� ��� ���." << endl;

    ranger(array1,SIZE); //������� �������������� �����
    printer(array1,SIZE);

    position = rand_searcher(array1,SIZE); //������� ���������� ������� ����� �� ���������


    cout << "����������� ������ ����� � ������ �� " << position+1 << "-� �������" << endl;

    sorter(array1,SIZE,position);
    printer(array1,SIZE);

    return 0;
}
