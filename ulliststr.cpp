#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  if (head_ == NULL) {
    return 0;
  }
  int size = 0;
  if (head_ != tail_) {
    size += head_->last - head_->first;
    size += tail_->last - tail_->first;
    size += ARRSIZE * (size_ - 2);
  } else {
    size += head_->last - head_->first;
    size += ARRSIZE * (size_ - 1);
  }
  return size;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (tail_ == NULL) {
    Item* node = new Item();
    head_ = tail_ = node;
    size_++;
  } else if (tail_->last == ARRSIZE) {
    Item* node = new Item();
    tail_->next = node;
    node->prev = tail_;
    tail_ = node;
    size_++;
  }

  tail_->val[tail_->last++] = val; 
}

void ULListStr::pop_back() {
  if (tail_ == NULL) {
    throw std::invalid_argument("Empty List");
  }
  tail_->last--;
  if (tail_->first != tail_->last) {
    return;
  }

  // remove the last node
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = NULL;
    size_ = 0;
  } else {
    Item* del = tail_;
    tail_ = tail_->prev;
    tail_->next = NULL;
    size_--;
    delete del;
  }
}


void ULListStr::push_front(const std::string& val) {
  if (head_ == NULL) {
    Item* node = new Item();
    head_ = tail_ = node;
    size_++;

    head_->first = head_->last = ARRSIZE;
  } else if (head_->first == 0) {
    Item* node = new Item();
    head_->prev = node;
    node->next = head_;
    head_ = node;
    size_++;

    head_->first = head_->last = ARRSIZE;
  }

  head_->val[--head_->first] = val;
}

void ULListStr::pop_front() {
  if (head_ == NULL) {
    throw std::invalid_argument("Empty List");
  }
  head_->first++;
  if (head_->first != head_->last) {
    return;
  }

  // remove the first node
  if (head_ == tail_) {
    delete head_;
    head_ = tail_ = NULL;
    size_ = 0;
  } else {
    Item* del = head_;
    head_ = head_->next;
    head_->prev = NULL;
    size_--;
    delete del;
  }
}

std::string const & ULListStr::back() const {
  if (tail_ == NULL) {
    throw std::invalid_argument("Empty List");
  }
  return tail_->val[tail_->last - 1];
}


std::string const & ULListStr::front() const {
  if (head_ == NULL) {
    throw std::invalid_argument("Empty List");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (head_ == NULL || head_->first == head_->last) {
    return NULL;
  }
  Item* p = head_;
  int i = 0;
  int pos = p->first;
  while (p != NULL && i < loc) {
    i++;
    pos++;
    if (pos == ARRSIZE) {
      pos = 0;
      p = p->next;
    }
  }
  return &p->val[pos];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
