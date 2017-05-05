#include <iostream>
#include <fstream>
#include <cstdlib>

void fileReadGraph::Input() {// построение графа на основе матрицы смежности из файла
    char buff[255];
    for (int i=0;i<=255;i++) buff[i]=*""; // обнуляем связующую строку
    //const char* a = "C:\\test.txt";
    ifstream fin("C:\\test.txt");
    if (!fin.is_open()) 
        cout << "Файл не может быть открыт!\n"; 
    else
    {
        ////////////////////////////////////////////
        int number;
        char*pEnd;
        fin.getline(buff,sizeof(buff));
        number = strol(buff,&pEnd,10); // парсит первую строку с кол-во вершин
        setSize(number); // установили кол-во вершин
        for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        ///////////////////////////////////////////
        fin.getline(buff,sizeof(buff));
        char*graph::names_versh = new char[number]; /* выделили память               */
        for (int i=0, i < number, i++){     /*под массив с названиями вершин*/
            graph::names_versh[i]=buff[i];
        };
        for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        //////////////////////////////////////////
        for(int k=0; k<number; k++){ //заполняем наш граф пробегая по матрицы смежности
            fin.getline(buff,sizeof(buff));   //считывание первой строки матрицы
            for (int j=0; j<number; j++){    //пробежались по строке с номером k
                VecGraph[k][j]=buff[j];     //записали строку матрицы в наш граф
            }
            for (int i=0;i<=255;i++) buff[i]=*""; //обнулили
        }
        //////////////////////////////////////
    }
    fin.close();
}

void graph::Output(){
    ofstream fout("C:\\test.txt", ios_base::trunc);
    fout <<  //запись в файл строки с названиями вершин
    }
} 
