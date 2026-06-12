
# Mini Banking System

## What I Built

A Simple Terminal Banking Simulator 

Users can:

* Deposit money
* Withdraw money
* Check balance

Current implementation supports one account and basic validation.

---

## How I Built It

* Functions → separated operations
* Global state → shared balance across operations
* Parameters → passed transaction values
* Conditional logic → controlled operation flow
* Scope → controlled variable access

---

## Features

* Deposit
* Withdraw
* Balance checking
* Invalid option handling

---

## Thoughts

Originally didn't intend this to become a full-blown mini project but as I completed Chapter 7 and was doing 2-3 test programs to test myself, it started becoming larger than I expected. Unintentional but here's my First Mini Project! 

Started noticing:

* data ownership
* program flow
* need for file organization

Would redesign parts differently now.

## Known Issues / Limitations 
* Recursion stack overflow risk still remains even though it's less probable to get triggered now
* Only a Single account can exist at a time. 
* File I/O for persistent balance storage (after Ch 28 but could come earlier if needed in a mini-project/project)

