#pragma once
#include<vector>
#include<iostream>

#include "scale_database.hpp"

//****************************************************************************
namespace  harmony::query{
//****************************************************************************
class visitor
{
public:
  virtual void accept(const scale_entry& entry) = 0;
  virtual void done() {}
  virtual ~visitor() = default;
};

template<class container = std::vector<scale_entry>>
class query_results : public visitor
{
public:
  using iterator = typename container::iterator; 
  using const_iterator = typename container::const_iterator;

public:
  void accept(const scale_entry& entry) override
  {
    entries_.insert(entries_.end(), entry);
  }
  
  bool empty() const
  {
    return entries_.empty();
  }
  std::size_t size() const
  {
    return entries_.size();
  }
        
  iterator begin()
  {
    return entries_.begin();
  }
  iterator end()
  {
    return entries_.end();
  }
  const_iterator begin() const
  {
    return entries_.cbegin();
  }
  const_iterator end() const
  {
    return entries_.cend();
  }

private:
  container entries_;
};

class query_stream : public visitor
{
public:
  query_stream()
    : os_(&std::cout)
  {
  }

  explicit query_stream(std::ostream& os)
    : os_(&os)
  {
  }

  void accept(const scale_entry& entry) override
  {
    if (os_) (*os_) << entry.name << '\n';
  }

  void done() override
  {
    if (os_) (*os_) << std::flush;
  }

private:
  std::ostream* os_;
};


class query_count : public visitor
{
public:

  // Todo - accept(), count(), empty() methods
  
private:
  std::size_t count_ = 0;
};

//****************************************************************************
} // namespace harmony::query
//****************************************************************************