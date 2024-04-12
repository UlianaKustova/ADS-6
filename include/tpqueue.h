// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[5];
    int head, tail, count;
 public:
    TPQueue() {
        head = 0;
        tail = 0;
        count = 0;
    }
    void push(const T& item) {
        if (count >= size) {
            return -1;
        }   
        count++;
        int index = tail;
        for (int i = head; i < tail; i++) {
            if (item.prior > arr[i].prior) {
                index = i;
                break;
            }
        }
        for (int i = tail; i < index; i++) {
            arr[i % size] = arr[(i - 1) % size];
        }
        arr[index % size] = item;
        tail++;
    }
    T pop() {
        if (count == 0) {
            return "er";
        } else {
            int index1 = head % size;
            head++;
            return arr[index1];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
