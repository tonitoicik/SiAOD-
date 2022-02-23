/*
Задание 1 Определить эффективный алгоритм из двух предложенных,
используя оценку теоретической сложности каждого из алгоритмов и
емкостную сложность, решения следующей задачи: дан массив из n
элементов целого типа, удалить из массива все значения равные
заданному. */ 

#include <iostream>
#include <cstdlib>
#include <ctime>

#define FIRST_LENGTH 10;
#define SECOND_LENGTH 100;

using namespace std;

void FirstMethod( int *Arr, int length, int key )
{
  int * _Arr = new int [length]; //Создаём внутренний массив, чтобы не изменять изначальный
  for ( int i = 0; i < length; i++) // Заполняем его
  {
    _Arr[i] = Arr[i];
  }
  
  int Assignments = 0; // Присваивания
  int Compares = 0; // Сравнения
  int Increments = 0; 
  int Decrements = 0;
  
  int i = 0;
  while ( i < length )
  {
    
    if ( _Arr[i] == key )
    {
      Compares++; // Каждое сравнение - действие
      
      for ( int j = i; j <= length-1; j++)
      {
        _Arr[j] = _Arr[j+1];
        Assignments++; // Каждое присваивание - действие
      }
      length -= 1;
      Decrements++; // Каждое вычитание - действие
    }
    else 
    {
      i++;
      Increments++; // Каждый инкремент - действие
      Compares++; // Каждый else - действие
    }
  Compares++; // Каждый проход цикла While - действие 
  }
  
  cout << endl << " Первый алгоритм:" << endl;
  cout << " Количество присваиваний " << Assignments << endl;
  cout << " Количество сравнений " << Compares << endl;
  cout << " Количество инкрементов " << Increments << endl;
  cout << " Количество декрементов " << Decrements << endl;
  cout << " Суммарное кол-во операций " << Assignments+Compares+Increments+Decrements << endl;
  
  int * _FinalArr = new int [length]; // Создаём финальный массив с новой длинной и заполняем его
  cout << "Итоговый массив: ";
  for( int i = 0; i < length; i++)
  {
    _FinalArr[i] = _Arr[i];
    cout << _FinalArr[i]<<' ';
  }
  cout << endl << endl;

  delete [] _Arr; //Удаляем ненужный массив
}

void SecondMethod( int *Arr, int &length, int key ) // Теперь можно изменять массив с чистой совестью
{
  int Assignments = 0; // Присваивания
  int Compares = 0; // Сравнения
  int Increments = 0; 
  int Decrements = 0;
  
  int j = 0;
  for ( int i = 0; i < length ; i++ )
  {
    Arr[j] = Arr[i];
    Assignments++;
    if ( Arr[i] != key )
    {
      Compares++;
      j++;
      Increments++;
    }
  }
  length = j;
  Assignments++;
  cout << endl << " Второй алгоритм:" << endl;
  cout << " Количество присваиваний " << Assignments << endl;
  cout << " Количество сравнений " << Compares << endl;
  cout << " Количество инкрементов " << Increments << endl;
  cout << " Количество декрементов " << Decrements << endl;
  cout << " Суммарное кол-во операций " << Assignments+Compares+Increments+Decrements << endl;

  int *FinalArr = new int [length];
  cout << "Итоговый массив: ";
  for( int i = 0; i < length; i++)
  {
    FinalArr[i] = Arr[i];
    cout << FinalArr[i]<<' ';
  }
  delete [] Arr; // Удаляем чтобы не валялось :) 
  
  cout << endl; 
}

int main() {
  int length = FIRST_LENGTH;
  int *MyTestArr = new int [length] { 1 , 2 , 3 , 2 , 2 , 2 , 5 , 2 , 2 , 2 };
  int key = 2;
  
  FirstMethod(MyTestArr, length, key);
  SecondMethod(MyTestArr, length, key);

  length = SECOND_LENGTH;
  srand(time(0));
  
  int *MyRandomArr = new int [length];
  cout << endl << " Изначальный массив на 100 элементов: ";
  for ( int i = 0; i < length; i++)
  {
    MyRandomArr[i] = ( rand() % 10 );
    cout << MyRandomArr[i]<< ' ';
  }
  cout << endl;
  
  FirstMethod(MyRandomArr, length, key);
  SecondMethod(MyRandomArr, length, key);

}
