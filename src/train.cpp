// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) return;
  Car* cur = first->next;
  while (cur != first) {
    Car* tmp = cur;
    cur = cur->next;
    delete tmp;
  }
  delete first;
}

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
  if (!first->light) {
    first->light = true;
    Car* cur = first;
    int len = 0;
    int laps = 0;
    while (true) {
      cur = cur->next;
      ++countOp;
      if (laps == 0) ++len;
      if (cur == first) {
        ++laps;
        if (laps == 2) {
          first->light = false;
          return len;
        }
      }
      if (cur->light) cur->light = false;
    }
  } else {
    int k = 1;
    int firstEncounters = 0;
    while (true) {
      Car* cur = first;
      for (int i = 0; i < k; ++i) {
        cur = cur->next;
        ++countOp;
      }
      if (cur == first) ++firstEncounters;
      if (cur->light) {
        if (cur != first || firstEncounters == 2) {
          cur->light = false;
        }
      }
      for (int i = 0; i < k; ++i) {
        cur = cur->prev;
        ++countOp;
      }
      if (!first->light) return k;
      ++k;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
