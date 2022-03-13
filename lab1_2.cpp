// lab1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>
using namespace std;
class Student {
public:
    
     char name[27];
     char date_of_birht[12];
     float grades[8];
     int course;
     int group;
     
     float average(float grades[8]) {
         float average = 0;
         for (int b = 0; b < 8; b++) { average += grades[b]; }
         return average / 8;
     }
    
};
int main()
{ setlocale(0, "ru");
    cout << endl << "name surname second name - имя фамилия отчество + номер в списке\n" << endl;
   
    int b, v; float d; int k[8];
    ifstream fin;
    fin.open("TextFile1.txt");
    Student st[8];
    char empty[1];
    float averages[8];
    cout << "Изначальный список студентов : " << endl;
    for(b=0;b<8;b++) {
        fin.read(empty, 1);// решает непонятную проблему с чтением данных
        fin.getline(st[b].name, 27,'\n');
        fin.getline(st[b].date_of_birht, 12,'\n');
        for (v = 0; v < 8; v++) { fin >> st[b].grades[v]; }
        averages[b] = st[b].average(st[b].grades);
         cout<< st[b].name << " : " << averages[b] << endl;
        fin >> st[b].course;
        fin >> st[b].group;
        k[b] = b;
        
    }
    for (v = 0; v < 2; v++) {

        for (b = 0; b < 7; b++) {

            if (averages[b] < averages[b + 1]) {
                d = averages[b]; averages[b] = averages[b + 1]; averages[b + 1] = d; d = k[b]; k[b] = k[b + 1]; k[b + 1] = d;
            }

        }

    }cout << "Упорядоченный список студентов : \n";
        for (b = 0; b < 8; b++)cout<<st[k[b]].name<<" : "<< averages[b] <<  endl;
        fin.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
