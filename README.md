# C++ for newbs

#### 📌 Some Basics Concepts for C++ (after learning C)
https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/Sy6jdBIcJx

#### 📌 Contructor & Destructor
https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/rJPm_t4oJx

#### 📌 Getter Method
https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/H1eQh3oj1x

#### 📌 File Handling (Open / Write / Close)
https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/r1TCoR4hJg

## Notes for each Project

### 0️⃣ CPP-00
+ [Walk-thru] For bonus ex2, Understanding Reverse Engineering:
https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/rJndvhisye

****************************************************************************

### 1️⃣ CPP-01 (Pointer/Reference / File Handlings / Switch Statement)
+ Pointer & Reference in C++ : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/rkVAGOghyg

****************************************************************************

### 2️⃣ CPP-02 (Orthodox Canonical class form / Fixed-Point / Operator Overload)

+ Orthodox Canonical class form : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/ry9Uc8TTyl
+ Fixed- Point : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/S1uenO661l
+ Operator overload : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/BJRoauTTkx
****************************************************************************

### 3️⃣ CPP-03 (Inheritance / Class Ambiguity)
+ Inheritance (Abstract & Concrete class) : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/S1IIYb2pkg  
+ Multiple Inheritance Ambiguity : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/SJTVPv-0Je
****************************************************************************

### 4️⃣ CPP-04 (Abstract Class v.s. Interface v.s. Derived Concrete Class / Subtype Polymorphism)
+ Abstract & Concrete class : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/S1IIYb2pkg
+ Abstract class & Polymorphism : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/B1IkDJV0ye
+ Shallow Copy v.s. Deep Copy
+ Abstract v.s. Interface

+ Ex03 | ENTIRE CLASSES STRUCTURES: 

 
       AMateria         (Base Abstract Class)
      /        \
    Ice         Cure    (Derived Concrete Class)


// In Base Abstract Class (AMateria):
// virtual ~AMateria();
// virtual AMateria* clone() const = 0;//pure virtual func
// virtual void use(ICharacter& target);//virtual func

// In Derived Concrete Class (Ice, Cure):
// AMateria* Cure::clone() const -> deep copy whole class (new Cure(*this))
// void Cure::use(ICharacter& target) -> need to implement

    ICharacter            (Interface)
        |
    Character             (Concrete class)

// In Ineterface (ICharacter):
// No variable / All is pure virtual func

// In Concrete Class (Character):
// !! NEED TO IMPLEMENT ALL PURE VIRTUAL FUNC !!
// void equip(AMateria* m);
// void unequip(int idx);
// void use(int idx, ICharacter& target);

    IMateriaSource        (Interface)
          |
    MateriaSource         (Concrete class)


*~~ REST IS THE SAME LOGIC AS ICharacter*

****************************************************************************

### 5️⃣ CPP-05 (Nested class, Try/Catch statement)
+ Nested class, Try/Catch statement : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/Bkk1hNupkl
+ Notes on Exception Classes : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/BJaCAwnAJl
****************************************************************************
### 6️⃣ CPP-06 (Casts)
+ Basic Terms/Notions : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/ByGYm7J1ee
+ 5 Main Cast Types : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/SyXVxQyyxg
****************************************************************************
### CPP-07 (Template)
+ Template Basics : https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/B1xYWHr1gl

