# Set Theory: A Comprehensive Guide

**Last Updated:** October 28, 2025

Set theory is the mathematical theory of well-defined collections of objects, which are called sets. It provides a foundational system for mathematics and is essential for understanding modern mathematical concepts.

---

## Table of Contents
1. [Introduction to Sets](#1-introduction-to-sets)
2. [Set Notation and Basic Definitions](#2-set-notation-and-basic-definitions)
3. [Set Operations](#3-set-operations)
4. [Venn Diagrams](#4-venn-diagrams)
5. [Special Sets](#5-special-sets)
6. [Cardinality](#6-cardinality)
7. [Power Sets](#7-power-sets)
8. [Cartesian Products](#8-cartesian-products)
9. [Relations and Functions](#9-relations-and-functions)
10. [Advanced Topics](#10-advanced-topics)

---

## 1. Introduction to Sets

### What is a Set?
A **set** is a well-defined collection of distinct objects, considered as an object in its own right. The objects that make up a set are called **elements** or **members** of the set.

### Key Properties
- Sets are **unordered**: $\{1, 2, 3\} = \{3, 2, 1\}$
- Elements are **distinct**: $\{1, 2, 2, 3\} = \{1, 2, 3\}$
- Sets are **well-defined**: It must be clear whether an object belongs to the set or not

### Examples
- $A = \{1, 2, 3, 4, 5\}$ - A set of integers
- $B = \{a, e, i, o, u\}$ - A set of vowels
- $C = \{x \mid x \text{ is a prime number less than 10}\}$ - A set defined by a property

---

## 2. Set Notation and Basic Definitions

### Membership
If $x$ is an element of set $A$, we write:
$$x \in A$$

If $x$ is not an element of set $A$, we write:
$$x \notin A$$

**Example:**
- Let $A = \{1, 2, 3, 4, 5\}$
- Then $3 \in A$ (3 is in A)
- But $7 \notin A$ (7 is not in A)

### Set Builder Notation
Sets can be defined using set builder notation:
$$S = \{x \mid P(x)\}$$
or
$$S = \{x : P(x)\}$$

This reads: "S is the set of all x such that P(x) is true"

**Examples:**
- $E = \{x \mid x \text{ is an even integer}\}$
- $P = \{x \in \mathbb{N} \mid x \text{ is prime}\}$
- $S = \{x \in \mathbb{R} \mid x^2 < 9\}$

### Subset
A set $A$ is a **subset** of set $B$ (written $A \subseteq B$) if every element of $A$ is also an element of $B$:
$$A \subseteq B \iff \forall x (x \in A \implies x \in B)$$

**Proper Subset:**
$A$ is a **proper subset** of $B$ (written $A \subset B$ or $A \subsetneq B$) if $A \subseteq B$ and $A \neq B$.

**Example:**
- $\{1, 2\} \subset \{1, 2, 3, 4\}$
- $\{1, 2, 3\} \subseteq \{1, 2, 3\}$
- Every set is a subset of itself

### Set Equality
Two sets $A$ and $B$ are **equal** if they contain exactly the same elements:
$$A = B \iff (A \subseteq B) \land (B \subseteq A)$$

---

## 3. Set Operations

### Union
The **union** of sets $A$ and $B$ is the set of all elements that belong to $A$, $B$, or both:
$$A \cup B = \{x \mid x \in A \lor x \in B\}$$

**Example:**
- $A = \{1, 2, 3\}$, $B = \{3, 4, 5\}$
- $A \cup B = \{1, 2, 3, 4, 5\}$

**Properties:**
- **Commutative:** $A \cup B = B \cup A$
- **Associative:** $(A \cup B) \cup C = A \cup (B \cup C)$
- **Identity:** $A \cup \emptyset = A$
- **Idempotent:** $A \cup A = A$

### Intersection
The **intersection** of sets $A$ and $B$ is the set of all elements that belong to both $A$ and $B$:
$$A \cap B = \{x \mid x \in A \land x \in B\}$$

**Example:**
- $A = \{1, 2, 3, 4\}$, $B = \{3, 4, 5, 6\}$
- $A \cap B = \{3, 4\}$

**Properties:**
- **Commutative:** $A \cap B = B \cap A$
- **Associative:** $(A \cap B) \cap C = A \cap (B \cap C)$
- **Identity:** $A \cap U = A$ (where $U$ is the universal set)
- **Idempotent:** $A \cap A = A$

### Disjoint Sets
Two sets are **disjoint** if they have no elements in common:
$$A \cap B = \emptyset$$

**Example:**
- $A = \{1, 2, 3\}$, $B = \{4, 5, 6\}$ are disjoint

### Difference
The **difference** of sets $A$ and $B$ (also called relative complement) is the set of elements in $A$ but not in $B$:
$$A - B = A \setminus B = \{x \mid x \in A \land x \notin B\}$$

**Example:**
- $A = \{1, 2, 3, 4, 5\}$, $B = \{3, 4, 5, 6\}$
- $A - B = \{1, 2\}$
- $B - A = \{6\}$

**Note:** $A - B \neq B - A$ (not commutative)

### Complement
The **complement** of set $A$ (with respect to universal set $U$) is the set of all elements in $U$ that are not in $A$:
$$A^c = \overline{A} = U - A = \{x \mid x \in U \land x \notin A\}$$

**Example:**
- If $U = \{1, 2, 3, 4, 5, 6, 7, 8, 9, 10\}$ and $A = \{2, 4, 6, 8, 10\}$
- Then $A^c = \{1, 3, 5, 7, 9\}$

**Properties:**
- $(A^c)^c = A$ (Double complement)
- $A \cup A^c = U$ (Law of excluded middle)
- $A \cap A^c = \emptyset$ (Law of non-contradiction)

### Symmetric Difference
The **symmetric difference** of sets $A$ and $B$ is the set of elements in either $A$ or $B$, but not in both:
$$A \triangle B = (A - B) \cup (B - A) = (A \cup B) - (A \cap B)$$

**Example:**
- $A = \{1, 2, 3, 4\}$, $B = \{3, 4, 5, 6\}$
- $A \triangle B = \{1, 2, 5, 6\}$

---

## 4. Venn Diagrams

Venn diagrams are visual representations of sets and their relationships.

### Basic Venn Diagrams

**Two Sets:**
- **Union:** The entire shaded region of both circles
- **Intersection:** The overlapping region where circles meet
- **Difference:** The region in one circle but not the other
- **Symmetric Difference:** Both circles excluding the intersection

**Three Sets:**
For sets $A$, $B$, and $C$, there are 8 distinct regions:
1. $A \cap B \cap C$ (center)
2. $(A \cap B) - C$
3. $(A \cap C) - B$
4. $(B \cap C) - A$
5. $A - (B \cup C)$
6. $B - (A \cup C)$
7. $C - (A \cup B)$
8. $(A \cup B \cup C)^c$

---

## 5. Special Sets

### Empty Set
The **empty set** (or null set) contains no elements:
$$\emptyset = \{\}$$

**Properties:**
- $\emptyset \subseteq A$ for any set $A$
- $|\emptyset| = 0$ (cardinality is zero)
- $A \cup \emptyset = A$
- $A \cap \emptyset = \emptyset$

### Universal Set
The **universal set** $U$ contains all elements under consideration in a particular context.

### Number Sets
Standard mathematical number sets:

- $\mathbb{N} = \{0, 1, 2, 3, 4, \ldots\}$ - Natural numbers (including zero)
- $\mathbb{N}^+ = \{1, 2, 3, 4, \ldots\}$ - Positive natural numbers
- $\mathbb{Z} = \{\ldots, -2, -1, 0, 1, 2, \ldots\}$ - Integers
- $\mathbb{Q} = \left\{\frac{p}{q} \mid p, q \in \mathbb{Z}, q \neq 0\right\}$ - Rational numbers
- $\mathbb{R}$ - Real numbers
- $\mathbb{C} = \{a + bi \mid a, b \in \mathbb{R}, i^2 = -1\}$ - Complex numbers

**Relationships:**
$$\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R} \subset \mathbb{C}$$

### Intervals (Subsets of Real Numbers)
- **Open interval:** $(a, b) = \{x \in \mathbb{R} \mid a < x < b\}$
- **Closed interval:** $[a, b] = \{x \in \mathbb{R} \mid a \leq x \leq b\}$
- **Half-open intervals:** $[a, b) = \{x \in \mathbb{R} \mid a \leq x < b\}$
- **Half-open intervals:** $(a, b] = \{x \in \mathbb{R} \mid a < x \leq b\}$

---

## 6. Cardinality

### Definition
The **cardinality** of a set $A$, denoted $|A|$ or $\#A$, is the number of elements in the set.

**Examples:**
- $|\{1, 2, 3\}| = 3$
- $|\{a, b, c, d, e\}| = 5$
- $|\emptyset| = 0$

### Finite and Infinite Sets
- A set is **finite** if it has a finite number of elements
- A set is **infinite** if it is not finite

**Examples:**
- $\{1, 2, 3, 4, 5\}$ is finite with cardinality 5
- $\mathbb{N}$ is infinite
- $\mathbb{R}$ is infinite (and uncountably infinite)

### Cardinality Formulas

#### Inclusion-Exclusion Principle
For two sets:
$$|A \cup B| = |A| + |B| - |A \cap B|$$

For three sets:
$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

**Example:**
- Let $A = \{1, 2, 3, 4\}$ and $B = \{3, 4, 5, 6\}$
- $|A| = 4$, $|B| = 4$, $|A \cap B| = 2$
- $|A \cup B| = 4 + 4 - 2 = 6$
- Indeed, $A \cup B = \{1, 2, 3, 4, 5, 6\}$ has 6 elements

#### Other Formulas
- $|A - B| = |A| - |A \cap B|$
- $|A \triangle B| = |A| + |B| - 2|A \cap B|$
- If $A$ and $B$ are disjoint: $|A \cup B| = |A| + |B|$

### Countable and Uncountable Sets
- A set is **countably infinite** if it can be put in one-to-one correspondence with $\mathbb{N}$
- A set is **uncountable** if it is infinite but not countably infinite

**Examples:**
- $\mathbb{N}$, $\mathbb{Z}$, and $\mathbb{Q}$ are countably infinite
- $\mathbb{R}$ is uncountably infinite (proven by Cantor's diagonal argument)

---

## 7. Power Sets

### Definition
The **power set** of a set $A$, denoted $\mathcal{P}(A)$ or $2^A$, is the set of all subsets of $A$:
$$\mathcal{P}(A) = \{S \mid S \subseteq A\}$$

**Example:**
If $A = \{1, 2, 3\}$, then:
$$\mathcal{P}(A) = \{\emptyset, \{1\}, \{2\}, \{3\}, \{1, 2\}, \{1, 3\}, \{2, 3\}, \{1, 2, 3\}\}$$

### Cardinality of Power Sets
If $|A| = n$, then:
$$|\mathcal{P}(A)| = 2^n$$

**Proof Idea:**
Each subset corresponds to a binary choice for each element: include it or not. With $n$ elements, there are $2^n$ such combinations.

**Examples:**
- $A = \{1, 2\}$: $|\mathcal{P}(A)| = 2^2 = 4$
  - $\mathcal{P}(A) = \{\emptyset, \{1\}, \{2\}, \{1, 2\}\}$
- $A = \emptyset$: $|\mathcal{P}(A)| = 2^0 = 1$
  - $\mathcal{P}(\emptyset) = \{\emptyset\}$

### Properties
- $\emptyset \in \mathcal{P}(A)$ for all sets $A$
- $A \in \mathcal{P}(A)$ for all sets $A$
- If $A \subseteq B$, then $\mathcal{P}(A) \subseteq \mathcal{P}(B)$

---

## 8. Cartesian Products

### Definition
The **Cartesian product** of sets $A$ and $B$, denoted $A \times B$, is the set of all ordered pairs $(a, b)$ where $a \in A$ and $b \in B$:
$$A \times B = \{(a, b) \mid a \in A \land b \in B\}$$

**Example:**
- $A = \{1, 2\}$, $B = \{x, y, z\}$
- $A \times B = \{(1, x), (1, y), (1, z), (2, x), (2, y), (2, z)\}$

### Properties
- **Not commutative:** $A \times B \neq B \times A$ (in general)
- **Cardinality:** $|A \times B| = |A| \times |B|$
- **With empty set:** $A \times \emptyset = \emptyset$

### n-fold Cartesian Product
For $n$ sets $A_1, A_2, \ldots, A_n$:
$$A_1 \times A_2 \times \cdots \times A_n = \{(a_1, a_2, \ldots, a_n) \mid a_i \in A_i \text{ for } i = 1, 2, \ldots, n\}$$

**Special case:**
$$A^n = \underbrace{A \times A \times \cdots \times A}_{n \text{ times}}$$

**Examples:**
- $\mathbb{R}^2 = \mathbb{R} \times \mathbb{R}$ (the plane)
- $\mathbb{R}^3 = \mathbb{R} \times \mathbb{R} \times \mathbb{R}$ (3D space)

---

## 9. Relations and Functions

### Relations
A **binary relation** $R$ from set $A$ to set $B$ is a subset of the Cartesian product:
$$R \subseteq A \times B$$

We write $a \, R \, b$ or $(a, b) \in R$ to denote that $a$ is related to $b$.

**Example:**
- Let $A = \{1, 2, 3\}$ and define "less than" relation
- $R = \{(1, 2), (1, 3), (2, 3)\} \subseteq A \times A$

### Properties of Relations on a Set $A$
A relation $R$ on $A$ (i.e., $R \subseteq A \times A$) can have these properties:

1. **Reflexive:** $\forall a \in A, (a, a) \in R$
2. **Symmetric:** $\forall a, b \in A, (a, b) \in R \implies (b, a) \in R$
3. **Antisymmetric:** $\forall a, b \in A, [(a, b) \in R \land (b, a) \in R] \implies a = b$
4. **Transitive:** $\forall a, b, c \in A, [(a, b) \in R \land (b, c) \in R] \implies (a, c) \in R$

### Equivalence Relations
A relation that is **reflexive**, **symmetric**, and **transitive** is called an **equivalence relation**.

**Example:** Equality ($=$) on any set is an equivalence relation.

### Functions
A **function** $f: A \to B$ is a special relation where each element of $A$ is related to exactly one element of $B$.

**Formally:**
$$f \subseteq A \times B \text{ such that } \forall a \in A, \exists! b \in B, (a, b) \in f$$

We write $f(a) = b$ instead of $(a, b) \in f$.

**Key Terms:**
- **Domain:** $\text{dom}(f) = A$
- **Codomain:** $B$
- **Range (Image):** $\text{range}(f) = \{f(a) \mid a \in A\} \subseteq B$

### Types of Functions

#### Injective (One-to-One)
$f: A \to B$ is **injective** if:
$$\forall a_1, a_2 \in A, f(a_1) = f(a_2) \implies a_1 = a_2$$

Equivalently: different inputs produce different outputs.

#### Surjective (Onto)
$f: A \to B$ is **surjective** if:
$$\forall b \in B, \exists a \in A, f(a) = b$$

Equivalently: every element of $B$ is mapped to by some element of $A$.

#### Bijective (One-to-One Correspondence)
$f: A \to B$ is **bijective** if it is both injective and surjective.

Bijective functions establish that two sets have the same cardinality.

---

## 10. Advanced Topics

### De Morgan's Laws
For any sets $A$ and $B$:
$$(A \cup B)^c = A^c \cap B^c$$
$$(A \cap B)^c = A^c \cup B^c$$

**Generalized De Morgan's Laws:**
$$\left(\bigcup_{i \in I} A_i\right)^c = \bigcap_{i \in I} A_i^c$$
$$\left(\bigcap_{i \in I} A_i\right)^c = \bigcup_{i \in I} A_i^c$$

### Distributive Laws
For any sets $A$, $B$, and $C$:
$$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$$
$$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$$

### Absorption Laws
For any sets $A$ and $B$:
$$A \cup (A \cap B) = A$$
$$A \cap (A \cup B) = A$$

### Partition of a Set
A **partition** of set $A$ is a collection of non-empty subsets $\{A_1, A_2, \ldots, A_n\}$ such that:
1. $A_i \cap A_j = \emptyset$ for $i \neq j$ (pairwise disjoint)
2. $A_1 \cup A_2 \cup \cdots \cup A_n = A$ (cover all of $A$)

**Example:**
$A = \{1, 2, 3, 4, 5, 6\}$ can be partitioned as:
- $\{\{1, 2\}, \{3, 4\}, \{5, 6\}\}$
- $\{\{1\}, \{2, 3, 4\}, \{5, 6\}\}$

### Axiom of Choice
The **Axiom of Choice** states that given a collection of non-empty sets, it is possible to choose exactly one element from each set, even if there is no explicit rule for making the choice.

**Equivalent Statements:**
- Every vector space has a basis
- Every set can be well-ordered
- Zorn's Lemma: If every chain in a partially ordered set has an upper bound, then the set has a maximal element

### Russell's Paradox
Consider the set $R = \{x \mid x \notin x\}$ (the set of all sets that do not contain themselves).

**Question:** Is $R \in R$?
- If $R \in R$, then by definition $R \notin R$ (contradiction)
- If $R \notin R$, then by definition $R \in R$ (contradiction)

This paradox led to the development of axiomatic set theory (ZFC - Zermelo-Fraenkel with Choice).

---

## Practice Problems

### Basic Problems

1. **Set Operations:**
   - Given $A = \{1, 2, 3, 4, 5\}$ and $B = \{4, 5, 6, 7\}$
   - Find: $A \cup B$, $A \cap B$, $A - B$, $B - A$, $A \triangle B$

2. **Cardinality:**
   - If $|A| = 5$, $|B| = 7$, and $|A \cap B| = 3$, find $|A \cup B|$

3. **Power Set:**
   - Find $\mathcal{P}(\{a, b\})$
   - What is $|\mathcal{P}(\{1, 2, 3, 4\})|$?

4. **Cartesian Product:**
   - If $A = \{1, 2\}$ and $B = \{a, b, c\}$, find $A \times B$ and $B \times A$

### Intermediate Problems

5. **Prove De Morgan's Law:**
   - Show that $(A \cup B)^c = A^c \cap B^c$

6. **Subsets:**
   - How many subsets does a set with 6 elements have?
   - How many proper subsets?

7. **Relations:**
   - Define a relation $R$ on $\{1, 2, 3, 4\}$ that is reflexive and symmetric but not transitive

### Advanced Problems

8. **Prove or Disprove:**
   - If $A \subseteq B$ and $B \subseteq C$, then $A \subseteq C$ (transitivity of subset)

9. **Cardinality:**
   - Prove that $|\mathbb{N}| = |\mathbb{Z}|$ by constructing a bijection

10. **Functions:**
    - Give an example of a function that is injective but not surjective
    - Give an example of a function that is surjective but not injective

---

## Solutions to Selected Problems

### Problem 1
- $A \cup B = \{1, 2, 3, 4, 5, 6, 7\}$
- $A \cap B = \{4, 5\}$
- $A - B = \{1, 2, 3\}$
- $B - A = \{6, 7\}$
- $A \triangle B = \{1, 2, 3, 6, 7\}$

### Problem 2
Using inclusion-exclusion:
$$|A \cup B| = |A| + |B| - |A \cap B| = 5 + 7 - 3 = 9$$

### Problem 3
$$\mathcal{P}(\{a, b\}) = \{\emptyset, \{a\}, \{b\}, \{a, b\}\}$$
$$|\mathcal{P}(\{1, 2, 3, 4\})| = 2^4 = 16$$

### Problem 6
- Number of subsets: $2^6 = 64$
- Number of proper subsets: $2^6 - 1 = 63$ (excluding the set itself)

---

## Applications of Set Theory

### Computer Science
- **Databases:** Query operations (union, intersection, difference)
- **Programming:** Data structures (sets, hash tables)
- **Logic:** Boolean algebra and circuit design
- **Algorithms:** Graph theory, complexity theory

### Probability and Statistics
- **Sample spaces:** Sets of all possible outcomes
- **Events:** Subsets of sample spaces
- **Probability rules:** Based on set operations

### Logic and Foundations
- **Mathematical logic:** Predicates and quantifiers
- **Model theory:** Interpretations of logical systems
- **Category theory:** Generalizations of set-theoretic concepts

---

## Summary

### Key Concepts Covered
✓ Set notation and basic definitions  
✓ Set operations (union, intersection, difference, complement)  
✓ Venn diagrams and visual representations  
✓ Cardinality and inclusion-exclusion principle  
✓ Power sets and their properties  
✓ Cartesian products and ordered pairs  
✓ Relations and their properties  
✓ Functions (injective, surjective, bijective)  
✓ Advanced topics (De Morgan's laws, partitions, axioms)  

### Important Formulas

**Cardinality:**
- $|A \cup B| = |A| + |B| - |A \cap B|$
- $|\mathcal{P}(A)| = 2^{|A|}$
- $|A \times B| = |A| \times |B|$

**Set Laws:**
- **De Morgan's:** $(A \cup B)^c = A^c \cap B^c$ and $(A \cap B)^c = A^c \cup B^c$
- **Distributive:** $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
- **Absorption:** $A \cup (A \cap B) = A$

---

## Further Reading

### Recommended Texts
1. **Naive Set Theory** by Paul Halmos
2. **Introduction to Set Theory** by Karel Hrbacek and Thomas Jech
3. **Set Theory and Logic** by Robert R. Stoll
4. **Axiomatic Set Theory** by Patrick Suppes

### Online Resources
- [Set Theory on Wikipedia](https://en.wikipedia.org/wiki/Set_theory)
- [Wolfram MathWorld: Set Theory](http://mathworld.wolfram.com/SetTheory.html)
- [Stanford Encyclopedia of Philosophy: Set Theory](https://plato.stanford.edu/entries/set-theory/)

---

*Document verified and formatted with proper LaTeX notation - October 28, 2025*
