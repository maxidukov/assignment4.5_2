#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <limits>

void print_pyramid(int*,int);
void print_elem(int*,int);
bool make_move_err(std::string,int,int&,bool&);

inline void clear_stdin(){
  //std::cin.clear();
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main() {
  int aa[3][10] = {
  {1,3,6,5,9,8},
{94,67,18,44,55,12,6,42},
  {16,11,9,10,5,6,8,1,2,4},

};
  int asizes[] = {6,8,10};
  int numarr = 3;
  int current = 0;
  bool over = false;
  bool next_pyr = false;
  std::string cmd = "";
  for(int i{};i<numarr;i++){
    print_pyramid(aa[i],asizes[i]);
    current = 0;
    over = false;
    do{
      std::cout<<"Вы находитесь здесь: ";
      print_elem(aa[i],current);
      std::cout<<"Введите команду: ";
      std::cin>>std::setw(254)>>cmd;
      if(!make_move_err(cmd,asizes[i],current,over)){
        std::cout<<"Ок\n";
      }
      clear_stdin();
    }while(!over);
    if(i<numarr-1){
       while(1){
         std::cout<<"Следующая пирамида?(да/нет): ";
         std::cin>>std::setw(254)>>cmd;
         if(cmd=="нет"){
           next_pyr = false;
           break;
         }else if(cmd=="да"){
           next_pyr = true;
           break;
         }else{
          std::cout<<"Ответ непонятен...\n";
         }
         clear_stdin();
       }
       clear_stdin();
       if(!next_pyr){
          break;
       }
    }
  }
  return 0;
}

void print_pyramid(int* arr, int size){
   std::cout<<"Исходный массив: ";
   for(int i{};i<size;i++){
     std::cout<<arr[i]<<" ";
   }
   std::cout<<"\nПирамида:\n";
   for(int i{};i<size;i++){
     print_elem(arr,i);
   }
   std::cout<<"\n";
}

void print_elem(int* arr, int i){
   std::cout<<(int)(log2(i+1));
    if(i==0){
      std::cout<<" root ";
    }else{
      if(i%2==0){
         std::cout<<" right";
      }else{
         std::cout<<" left";
      }
      std::cout<<"("<<arr[(i-1)/2]<<") ";
    }
    std::cout<<arr[i]<<std::endl;
}
bool make_move_err(std::string cmd, int size, int& current, bool& over){
  if(cmd=="up"){
    if(current==0){
      std::cout<<"Ошибка! Отсутствует родитель\n";
    }else{
      current = (current-1)/2;
      return false;
    }
  }else if(cmd=="left"){
    if(2*current+1>=size){
      std::cout<<"Ошибка! Отсутствует левый потомок\n";
    }else{
      current = 2*current+1;
      return false;
    }
  }else if(cmd=="right"){
    if(2*current+2>=size){
      std::cout<<"Ошибка! Отсутствует правый потомок\n";
    }else{
      current = 2*current+2;
      return false;
    }
  }else if(cmd=="exit"){
    over = true;
  }else{
    std::cout<<"Неизвестная команда. Попробуйте ещё раз.\n";
  }
  return true;
}
