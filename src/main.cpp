// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  std::srand(std::time(nullptr));
  std::ofstream out("result/data.csv");
  out << "n,all_off,all_on,random\n";
  for (int n = 2; n <= 200; n += 2) {
    Train offTrain, onTrain, randTrain;
    for (int i = 0; i < n; ++i) {
      offTrain.addCar(false);
      onTrain.addCar(true);
      randTrain.addCar(std::rand() % 2 == 1);
    }
    offTrain.getLength();
    int offOps = offTrain.getOpCount();
    onTrain.getLength();
    int onOps = onTrain.getOpCount();
    randTrain.getLength();
    int randOps = randTrain.getOpCount();
    out << n << "," << offOps << "," << onOps << "," << randOps << "\n";
  }
  out.close();
  std::cout << "Data saved to result/data.csv" << std::endl;
  return 0;
}
