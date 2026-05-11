// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* car = new Car{light, nullptr, nullptr};
  if (!first) {
    car->next = car;
    car->prev = car;
    first = car;
  } else {
    car->next = first;
    car->prev = first->prev;
    first->prev->next = car;
    first->prev = car;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  first->light = true;
  int k = 1;
  while (true) {
    Car* cur = first;
    for (int i = 0; i < k; ++i) {
      cur = cur->next;
      ++countOp;
    }
    if (cur->light) {
      cur->light = false;
      for (int i = 0; i < k; ++i) {
        cur = cur->prev;
        ++countOp;
      }
      if (!first->light) {
        return k;
      }
    } else {
      for (int i = 0; i < k; ++i) {
        cur = cur->prev;
        ++countOp;
      }
    }
    ++k;
  }
}

int Train::getOpCount() {
  return countOp;
}
