

//******** Copyright � 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Predicate-based query system for scales
//*
//*
//****************************************************************************
#pragma once
//****************************************************************************
#pragma once
#include <vector>
#include <ostream>

#include "scale_query.hpp" 
#include "scale_visitor.hpp"

//****************************************************************************
namespace harmony::query{
//****************************************************************************

  template<structure_predicate P>
  class query_view
  {
  public:
    
    explicit query_view(P pred) : pred_(pred) {}

    [[nodiscard]] optional_scale_entry first() const
    {
      return find_first(pred_);
    }

    std::vector<scale_entry> collect() const
    {
      query_results qr;
      visit(pred_, qr);
      return std::vector <scale_entry>(qr.begin(), qr.end());
    }

    void stream(std::ostream& os) const
    {
      query_stream qs(os);
      visit(pred_, qs);
    }
    [[nodiscard]] bool empty() const
    {
      return !find_first(pred_).has_value(); // think - should use query_count visitor or short circuit??
    }

    [[nodiscard]] std::size_t count() const
    {
      // todo - query_count visitor and use it here-
    }

    void apply(visitor& v) const // bring your own visitor. does it belong here?
    {
      visit(pred_, v);
    }

  private:
    P pred_;
  };

  template<structure_predicate P>
  inline auto find(P pred)
  {
    return query_view<P>(pred);
  }

} // namespace harmony::query