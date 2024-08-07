//Name: Kimble Culley
//Date: 8/7/24
//Brief: The monty hall problem
//Description: This code allows for users to pick how many iterations and whether
// or not they want to switch doors for the simulations.



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool monty_hall(bool switch_choice){
  vector<int> doors = {0, 1, 2,};
  random_shuffle(doors.begin(), doors.end());

  int user_choice = rand() % 3;
  int host_choice;

  do{
    host_choice = rand() % 3;
  }while(host_choice == user_choice || doors[host_choice] == 0);

  if(switch_choice){
    for(int i = 0; i < 3; i++){
      if(i != user_choice && i != host_choice){
	user_choice = i;
	break;
      }
    }
  }

  return doors[user_choice] == 0;

}

void simulate(int num_iterations, bool switch_choice){
  int wins = 0;

  for(int i = 0; i < num_iterations; i++){
    if(monty_hall(switch_choice)){
      wins++;
    }
  }

  cout << "Results after " << num_iterations << " iterations:" << endl;
  cout << "Wins: " << wins << endl;
  cout << "Losses: " << num_iterations - wins  << endl;
  cout << "Win percentage: " << static_cast<double>(wins) / num_iterations * 100 << "%" << endl;

}



int main(){
  srand(static_cast<unsigned>(time(0)));

  int num_iterations;
  char choice;
  bool switch_choice;

  cout << "Enter the number of iterations for the simulation: ";
  cin >> num_iterations;

  cout << "Do you want to switch doors? (y/n): ";
  cin >> choice;

  switch_choice = (choice == 'y' || choice == 'Y');

  simulate(num_iterations, switch_choice);

  return 0;
  
}
