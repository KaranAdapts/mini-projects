
## 11 June 2026

### Lessons Learned

(Things that changed how I think.)

* Program Structure Matters 
* Program Flow Matters 
* Functions should preferably be Dumb and Simple! 

---

### Bugs Encountered

Bug:
Invalid Input to `proceedOperation()` kept spamming `"Invalid Option! Choose again!"` when something other than available options was input by the User and didn't ask for new input as intended. 

Cause:
the invalid input else block which had : 
`proceedOperation(userInput, balance, enterAmount(userInput)); `
Due to a logic bug, it kept supplying the same userInput repeatedly to the function instead of asking for a new User input hence, it kept executing the else block repeatedly and at some point caused Stack Overflow and ultimately, Segmentation fault. 
**My first Segmentation fault I've caused by the way!**

Fix:
Created `reUserInput` variable initialized by `takeInput()` to store 
the new valid input, then passed it correctly to both `proceedOperation()` 
and `enterAmount()` instead of the original invalid `userInput`.

Lesson:
When fixing bugs inside recursive calls, ensure the corrected variable 
is passed consistently to ALL parameters, not just some. 
Learn to name variables and parameters clearly to prevent confusion between the original 
and new values.

---

### Design Thoughts

(Architecture / ugly parts / ideas.)

Global balance made ownership unclear.
The recursion part for `proceedOperation()` was ugly and caused bad program flow but with my current knowledge that's what I could come up with. 

---

### Future Upgrades

* Refactor with Separate files
* Confirmation step for withdraw and deposit amount
* Better validation checking mechanism
* Refactor `proceedOperation()` to void — remove unnecessary return values
* Replace recursion with loops for input validation (after Ch 8)

