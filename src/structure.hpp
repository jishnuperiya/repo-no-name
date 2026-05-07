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
                                     structure(std::uint16_t bits) : structure(std::bitset<12>(bits & 0b111111111111)) {}

   /*
   QUESTION 3 : i could have implemented a catalog lookup inside the constructor to construct the name_ 
   using the provided intervals. then the ctor will have the extra cost of this catalog look up.
   so what is the best solution? only set the name_ using set_name() function?
   */

  public:                         // Operations
    bool                             operator==(const structure& other) const;
    bool                             operator!=(const structure& other) const = default;
    scale                            make_scale(note root)       const; 
    std::optional<structure>         mode(int degree)            const;
    
  public:                         // Queries
    int                              cardinality()               const;
    bool                             contains(int interval)      const;
    // QUESTION: i could have just used the note class instead of integer!!
    bool                             has_tritone()               const; 
    int                              brightness()                const;
    structure                        complement()                const; 

 /*   bool                             is_subset_of(const structure& other) const;
    bool                             is_superset_of(const structure& other) const;*/

    std::optional<std::string>       name()                      const;
    /*
    I could add methods like all_modes() which just call mode() for every degree from 1 to cardinality()
    shoud I provide things like these? - jonathon has mentioned the idea of minimal spanning set.
    */

  private:                        // Name Accessors
    structure&                       set_name(std::string_view n);
    /*
    QUESTION 2 : return structure& to make the set_name method chainable - fine?
    check usage: mode() function return statement.
    */
    void                             clear_name();

  private:                        // Representation
    std::bitset<12>                  intervals_; 
    std::optional<std::string>       name_; // better to lookup in catalog and not store here


    /*
    QUESTION 1 :
    Previously the name_ was a  optional<string_view> - BUT: I am pointing to something i dont control
    so went back to string - but not performance critical right? so what would be the right type for this?
    */

    /*
    QUESTION 4 :
    set_name() i made it to priavate. what if the user of our library has a exotic mode whose name isnt 
    available in our catalog but want to name it?

    i intentionally made it private because i didnt want user to give some funky name for scale structures
    which has a proper name in the catalog.
    */

    /*
    * QUESTION 5:
    note_set and structure::intervals are both bitset<12> but different semantics -
    one is absolute and other relative.
    
    but i wish my structure class had iterator support. should i make design a new type called 
    interval_set like note_set with iterator support
    */
 
    /*
    QUESTION 6:
    in the class, all the operations operates purely on the intervals_ and completely ignores the name_
    so is it a pure value type. somehting wrong here, isnt it? name_ is like a metadata - is it a
    good type design???
    */
  };
   
  std::ostream& operator<<(std::ostream& os, const structure& s); //todo

//****************************************************************************
} // namespace harmony
//****************************************************************************


