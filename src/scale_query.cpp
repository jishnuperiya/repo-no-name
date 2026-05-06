//******** Copyright © 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Implementation of predicate-based query system for scales.
//*
//*
//****************************************************************************

#include "scale_query.hpp"

//****************************************************************************
namespace harmony::query{
//****************************************************************************

  using scale_database::catalog;

/**
 * Return a pointer to the first catalog entry matching the predicate,
 * or nullptr if none matches.
 *
 * @param pred  The predicate to test each catalog entry against.
 */
  [[nodiscard]] optional_scale_entry find_first(const predicate& pred)
  {
    for (const auto& entry : catalog())
    {
      if (pred(entry.pattern))
      {
        return entry;
      }
    }
    return std::nullopt;
  }

  void visit(const predicate& pred, visitor& v)
  {
    for (const auto& entry : catalog())
    {
      if (pred(entry.pattern))
      {
        v.accept(entry);
      }
    }

  }



//****************************************************************************
} // namespace harmony::query
//****************************************************************************
