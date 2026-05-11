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
  int len = 1;
  Car* cur = first;
  while (true) {
    cur = cur->next;
    ++countOp;
    if (cur->light) {
      cur->light = false;
      len = 1;
    } else {
      ++len;
    }
    if (cur == first && !first->light) {
      return len - 1;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
