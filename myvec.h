#ifndef MY_VEC_H_
#define MY_VEC_H_

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

#define BLOCK_SIZE 128
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define ROUND_UP(bytes, align) (((bytes) + (align)-1) & ~((align)-1))

class myvec {
 public:
  myvec() : length_(0), capacity_(BLOCK_SIZE) {
    buf_ = (char *)malloc(BLOCK_SIZE);
  }
  ~myvec() {
    if (buf_ != NULL) {
      free(buf_);
    }
  }

  void append(char *str, size_t len) {
    if (len + length_ > capacity_) {
      capacity_ = ROUND_UP(MIN((capacity_ << 1), length_ + len), BLOCK_SIZE);
      buf_ = (char *)realloc(buf_, capacity_);
    }
    assert(buf_ != NULL);
    memcpy(&buf_[length_], str, len);
  }

 private:
  char *buf_;
  size_t length_;
  size_t capacity_;
};

class origin {
 public:
  origin() {}
  ~origin() {}

  void append(char *str, size_t len) {
    buf_.insert(buf_.end(), (const char *)str, (const char *)str + len);
  }

 private:
  std::vector<char> buf_;
};

#undef BLOCK_SIZE

#endif