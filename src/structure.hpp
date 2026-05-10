//******** Copyright � 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Implementation for class `harmony::structure`.
//*
//*
//****************************************************************************
#pragma once
//****************************************************************************

#include <initializer_list>  // For initializer_list
#include <bitset>            // For bitset
#include <optional>          // For optional
#include <string_view>       // For string_view

#include "scale.hpp"

//****************************************************************************
namespace harmony{
//****************************************************************************
  /**
   * Represents a harmonic structure defined by a set of intervals.
   * 
   * A harmonic structure can generate scales by applying its interval
   * pattern to any root note. For example, a major scale structure
   * would contain intervals {0, 2, 4, 5, 7, 9, 11}.
   */
  class structure 
  {
  public:                         // Construction
                                     structure();
                                     structure(std::initializer_list<int> pattern);
                                     structure(std::bitset<12> bits);

  public:                         // Operations
    bool                             operator==(const structure& other) const;
    bool                             operator!=(const structure& other) const = default;
    scale                            make_scale(note root)       const; 
    std::optional<structure>         mode(int degree)            const;
    
  public:                         // Queries
    int                              cardinality()               const;
    bool                             contains(int interval)      const;
    bool                             has_tritone()               const; 
    int                              brightness()                const;
    structure                        complement()                const; 

    std::optional<std::string>       name()                      const;
    
  private:                        // Name Accessors
    structure&                       set_name(std::string_view n);
    void                             clear_name();

  private:                        // Representation
    std::bitset<12>                  intervals_; 
    std::optional<std::string>       name_; // better to lookup in catalog and not store here
  };
   
  std::ostream& operator<<(std::ostream& os, const structure& s); //todo

//****************************************************************************
} // namespace harmony
//****************************************************************************


