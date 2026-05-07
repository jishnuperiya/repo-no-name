//******** Copyright © 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Database of musical scales.
//*
//*
//****************************************************************************
#pragma once
//****************************************************************************

#include <array>
#include <string_view>
#include <vector>
#include <ranges>

#include "structure.hpp"

//****************************************************************************
namespace harmony{
//****************************************************************************

  struct scale_entry  
  {
    std::string_view name;       //QUESTION: non owning? dangling refernce issues??
    structure pattern;           
  };

  namespace scale_database
  {
    const std::vector<scale_entry>&     catalog();

    std::optional<const scale_entry*>   find_by_name(std::string_view);
    size_t                              size();
  }

  constexpr auto all_structures()
  {
    std::views::iota(1, 1 << 11)
      | std::views::transform([](int i)
        {
          return structure(2 * i + 1);
        });

  }

  std::optional<structure> get_structure_by_name(std::string_view s);
//****************************************************************************
} // namespace harmony
//****************************************************************************