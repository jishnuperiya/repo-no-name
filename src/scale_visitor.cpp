//******** Copyright � 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Implementation for class `harmony::query::scale_visitor`.
//*
//*
//****************************************************************************

#include <iostream>
#include <vector>

#include "scale_visitor.hpp"
#include "scale_database.hpp"
//****************************************************************************
namespace  harmony::query{
//****************************************************************************

  void query_results::accept(const scale_entry& entry)
  {
    entries_.push_back(entry);
  }

  // container like accessors
  const std::vector<scale_entry>& query_results::entries() const 
  {
    return entries_; 
  }
  bool query_results::empty() const 
  {
    return entries_.empty(); 
  }
  std::size_t query_results::size() const 
  {
    return entries_.size(); 
  }
  //iterator support
  query_results::iterator query_results::begin()
  {
    return entries_.begin(); 
  }
  query_results::iterator query_results::end()
  {
    return entries_.end();
  }
  query_results::const_iterator query_results::begin() const
  {
    return entries_.cbegin();
  }
  query_results::const_iterator query_results::end() const
  {
    return entries_.cend();
  }
  // query_stream implementations

  query_stream::query_stream()
    : os_(&std::cout)
  {
  }
  query_stream::query_stream(std::ostream& os)
    : os_(&os)
  {
  }
  void query_stream::accept(const scale_entry& entry) 
  {
    if (os_) (*os_) << entry.name << '\n';
  }

  void query_stream::done() 
  {
    if(os_) (*os_) << std::flush;
  }
//****************************************************************************
} // namespace harmony::query
//****************************************************************************