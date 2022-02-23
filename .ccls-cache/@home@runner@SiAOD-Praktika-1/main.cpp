/*
Задание 1 Определить эффективный алгоритм из двух предложенных,
используя оценку теоретической сложности каждого из алгоритмов и
емкостную сложность, решения следующей задачи: дан массив из n
элементов целого типа, удалить из массива все значения равные
заданному. */ 

#include <iostream>
#include <cstdlib>

using namespace std;

void FirstMethod( int *Arr, int &length, int key )
{
  int OperationsNum = 1;
  int i = 0;
  while ( i < length )
  {
    
    if ( Arr[i] == key )
    {
      
      for ( int j = i; j <= length-1; j++)
      {
        
        Arr[j] = Arr[j+1];
        OperationsNum++; // Каждое присвоение - действие
      }
      length -= 1;
      OperationsNum++; // Каждое вычитание - действие
      OperationsNum++; // Каждое сравнение - действие
    }
    else 
    {
      i++;
      OperationsNum++; // Каждый инкремент - действие
      OperationsNum++; // Каждый else - действие
    }
  OperationsNum++; // Каждый проход цикла While - действие 
  }
  cout << " Количество операций - " << OperationsNum << endl;
}

void SecondMethod( int *Arr, int &length, int key )
{
  int j = 0;
  for ( int i = 0; i < length ; i++ )
  {
    Arr[j] = Arr[i];
    if ( Arr[i] != key )
    {
      j++;
    }
  }
  length = j;
}

int main() {
  int length = 10;
  int MyTestArr[10] = { 1 , 2 , 3 , 2 , 2 , 2 , 5 , 2 , 2 , 2 };
  int key = 2;

  int choise = 0; 
  cout << "Введите 1 или 2, в зависимости от того, какой способ сортировки вы хотите применить"<<endl;
  cin >> choise;
  
  switch(choise)
  {
    case 1:
    {
      FirstMethod(MyTestArr, length, key);
      break;
    }
    case 2:
    {
        SecondMethod(MyTestArr, length, key);
        break;
    }
    default:
    {
      cout << " Вы ввели что-то не то";
      break;
    }
  }


  for( int i = 0; i < length; i++)
  {
    cout << MyTestArr[i]<<' ';
  }

}