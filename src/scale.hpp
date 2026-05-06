//******** Copyright � 2026 Jishnu Periya, Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose : Implementation for class `harmony::scale`.
//*
//*
//****************************************************************************
#pragma once
//****************************************************************************
#include <ostream>           // For ostream

#include "note_set.hpp"

//****************************************************************************
namespace harmony
{
  //****************************************************************************

  class scale
  {
  public:          // Construction
                      scale(note root, note_set notes);
                      /*
                      QUESTION 2: should i make this constructor as private and make class strdutcure a friend?
                      so only structure could construct a scale?
                      so the scale can only be built by the strducture. 
                      -> but is it bad to make this tight coupling between classes?
                      is dependency bad?

                      */
                      /*
                      QUESTION 1:
                      my invariant for this class is that scale should always has a root and non-empty
                      set of notes. so i didnt provide any default ctor. is it the right call?
                      */
                      
  public:          // Operations
    note              get_root() const;
    note_set          get_notes() const;
  
  private:         // Representation
    note              root_;
    note_set          notes_;
  };

  std::ostream&       operator<<(std::ostream& os, const scale& scale);
}