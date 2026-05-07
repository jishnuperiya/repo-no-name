//******** Copyright © 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*  Purpose : Range-based lazy query system using C++23 ranges
//****************************************************************************
#pragma once

#include <ranges>

#include "scale_database.hpp"
#include "scale_query.hpp"


namespace harmony::query
{
  template<structure_predicate P>
  class scale_filter_view 
  {
  public:
    class iterator;

  public:
    explicit scale_filter_view(P pred)
      : pred_{ pred }
    {
    }

    auto begin() const
    {
      return iterator(&harmony::scale_database::catalog(), pred_, 0);
    }

    auto end() const
    {
      return iterator(&harmony::scale_database::catalog(), pred_, harmony::scale_database::catalog().size());
    }

    class iterator
    {
    public:
      using value_type = harmony::scale_entry;
      using difference_type = std::ptrdiff_t;

    public:

      iterator(const std::vector<harmony::scale_entry>* database, P pred, std::size_t start_index)
        : db_(database), pred_(pred), index_(start_index)
      {
        advance_to_match();
      }

      const harmony::scale_entry& operator*() const
      {
        return (*db_)[index_];
      }

      iterator& operator++()
      {
        ++index_;
        advance_to_match();
        return *this;
      }
      iterator operator++(int)
      {
        auto tmp = *this;
        ++(*this);
        return tmp;
      }

      bool operator==(const iterator& other) const
      {
        return db_ == other.db_ && index_ == other.index_;
      }

      bool operator!=(const iterator& other) const
      {
        return !(*this == other);
      }

    private:

      void advance_to_match()
      {
        while (index_ < db_->size() && !pred_((*db_)[index_].pattern))
        {
          ++index_;
        }
      }
      const std::vector<harmony::scale_entry>* db_; // tightly coupled - make it point to any range
      P pred_;
      std::size_t index_;
    };
  private:
    P pred_;
  };
}