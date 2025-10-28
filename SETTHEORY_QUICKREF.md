# Set Theory Quick Reference Guide

**Quick lookup for common set theory notation, formulas, and operations**

---

## 📌 Basic Notation

| Symbol | Meaning | Example |
|--------|---------|---------|
| $\in$ | Element of | $3 \in \{1,2,3\}$ |
| $\notin$ | Not element of | $5 \notin \{1,2,3\}$ |
| $\subseteq$ | Subset | $\{1,2\} \subseteq \{1,2,3\}$ |
| $\subset$ or $\subsetneq$ | Proper subset | $\{1,2\} \subset \{1,2,3\}$ |
| $\emptyset$ or $\{\}$ | Empty set | $\emptyset$ |
| $\cup$ | Union | $\{1,2\} \cup \{2,3\} = \{1,2,3\}$ |
| $\cap$ | Intersection | $\{1,2,3\} \cap \{2,3,4\} = \{2,3\}$ |
| $-$ or $\setminus$ | Difference | $\{1,2,3\} - \{2,3\} = \{1\}$ |
| $A^c$ or $\overline{A}$ | Complement | If $U=\{1,2,3,4\}$, $A=\{1,2\}$, then $A^c=\{3,4\}$ |
| $\triangle$ | Symmetric difference | $\{1,2,3\} \triangle \{2,3,4\} = \{1,4\}$ |
| $\times$ | Cartesian product | $\{1,2\} \times \{a,b\} = \{(1,a),(1,b),(2,a),(2,b)\}$ |
| $\mathcal{P}(A)$ or $2^A$ | Power set | $\mathcal{P}(\{1,2\}) = \{\emptyset,\{1\},\{2\},\{1,2\}\}$ |
| $\|A\|$ or $\#A$ | Cardinality | $\|\{1,2,3\}\| = 3$ |

---

## 🔢 Standard Number Sets

| Set | Symbol | Description |
|-----|--------|-------------|
| Natural numbers | $\mathbb{N}$ | $\{0, 1, 2, 3, \ldots\}$ |
| Positive integers | $\mathbb{N}^+$ or $\mathbb{Z}^+$ | $\{1, 2, 3, \ldots\}$ |
| Integers | $\mathbb{Z}$ | $\{\ldots, -2, -1, 0, 1, 2, \ldots\}$ |
| Rational numbers | $\mathbb{Q}$ | $\{\frac{p}{q} \mid p,q \in \mathbb{Z}, q \neq 0\}$ |
| Real numbers | $\mathbb{R}$ | All rational and irrational numbers |
| Complex numbers | $\mathbb{C}$ | $\{a + bi \mid a,b \in \mathbb{R}, i^2=-1\}$ |

**Hierarchy:** $\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R} \subset \mathbb{C}$

---

## 📐 Key Formulas

### Cardinality
```
|A ∪ B| = |A| + |B| - |A ∩ B|

|A ∪ B ∪ C| = |A| + |B| + |C| 
              - |A ∩ B| - |A ∩ C| - |B ∩ C|
              + |A ∩ B ∩ C|

|A - B| = |A| - |A ∩ B|

|A △ B| = |A| + |B| - 2|A ∩ B|

|𝒫(A)| = 2^|A|

|A × B| = |A| × |B|
```

---

## 🧮 Set Laws

### Commutative Laws
```
A ∪ B = B ∪ A
A ∩ B = B ∩ A
```

### Associative Laws
```
(A ∪ B) ∪ C = A ∪ (B ∪ C)
(A ∩ B) ∩ C = A ∩ (B ∩ C)
```

### Distributive Laws
```
A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C)
A ∪ (B ∩ C) = (A ∪ B) ∩ (A ∪ C)
```

### De Morgan's Laws
```
(A ∪ B)ᶜ = Aᶜ ∩ Bᶜ
(A ∩ B)ᶜ = Aᶜ ∪ Bᶜ
```

### Identity Laws
```
A ∪ ∅ = A
A ∩ U = A
```

### Domination Laws
```
A ∪ U = U
A ∩ ∅ = ∅
```

### Idempotent Laws
```
A ∪ A = A
A ∩ A = A
```

### Complement Laws
```
A ∪ Aᶜ = U
A ∩ Aᶜ = ∅
(Aᶜ)ᶜ = A
Uᶜ = ∅
∅ᶜ = U
```

### Absorption Laws
```
A ∪ (A ∩ B) = A
A ∩ (A ∪ B) = A
```

---

## 🎯 Quick Examples

### Union
```
{1, 2, 3} ∪ {3, 4, 5} = {1, 2, 3, 4, 5}
```

### Intersection
```
{1, 2, 3, 4} ∩ {3, 4, 5, 6} = {3, 4}
```

### Difference
```
{1, 2, 3, 4, 5} - {3, 4, 5, 6} = {1, 2}
```

### Symmetric Difference
```
{1, 2, 3, 4} △ {3, 4, 5, 6} = {1, 2, 5, 6}
```

### Complement (with U = {1,2,3,4,5,6,7,8,9,10})
```
A = {2, 4, 6, 8, 10}
Aᶜ = {1, 3, 5, 7, 9}
```

### Power Set
```
𝒫({a, b}) = {∅, {a}, {b}, {a, b}}
```

### Cartesian Product
```
{1, 2} × {a, b} = {(1,a), (1,b), (2,a), (2,b)}
```

---

## 🔍 Proof Techniques

### Proving A ⊆ B
Show that if $x \in A$, then $x \in B$.

**Structure:**
1. Let $x \in A$ (arbitrary element)
2. Show that $x \in B$ (using definitions/properties)
3. Therefore $A \subseteq B$

### Proving A = B
Show both $A \subseteq B$ and $B \subseteq A$.

**Structure:**
1. Prove $A \subseteq B$
2. Prove $B \subseteq A$
3. Therefore $A = B$

### Proving Set Identities
Use:
- Set laws (commutative, associative, distributive, etc.)
- Element method (show $x \in$ LHS $\iff$ $x \in$ RHS)
- Venn diagrams (for intuition, not formal proof)

---

## 📊 Cardinality Reference

| Set | Cardinality | Type |
|-----|-------------|------|
| $\emptyset$ | 0 | Finite |
| $\{1, 2, 3\}$ | 3 | Finite |
| $\mathbb{N}$ | $\aleph_0$ | Countably infinite |
| $\mathbb{Z}$ | $\aleph_0$ | Countably infinite |
| $\mathbb{Q}$ | $\aleph_0$ | Countably infinite |
| $\mathbb{R}$ | $\mathfrak{c}$ (continuum) | Uncountably infinite |
| $\mathcal{P}(\mathbb{N})$ | $\mathfrak{c}$ | Uncountably infinite |

---

## 🎓 Common Mistakes to Avoid

### ❌ Wrong → ✅ Right

1. **Order matters:**
   - ❌ $\{1, 2\} \neq \{2, 1\}$
   - ✅ $\{1, 2\} = \{2, 1\}$ (sets are unordered)

2. **Duplicates:**
   - ❌ $\{1, 2, 2, 3\}$ has 4 elements
   - ✅ $\{1, 2, 2, 3\} = \{1, 2, 3\}$ has 3 elements

3. **Empty set vs set containing empty set:**
   - ❌ $\emptyset = \{\emptyset\}$
   - ✅ $\emptyset \neq \{\emptyset\}$ (first has 0 elements, second has 1)

4. **Subset vs element:**
   - ❌ $\{1\} \in \{1, 2, 3\}$
   - ✅ $1 \in \{1, 2, 3\}$ and $\{1\} \subseteq \{1, 2, 3\}$

5. **Complement requires universe:**
   - ❌ $\{1, 2\}^c = \{3, 4, 5, \ldots\}$ (undefined without $U$)
   - ✅ If $U = \{1, 2, 3, 4\}$, then $\{1, 2\}^c = \{3, 4\}$

6. **Difference is not commutative:**
   - ❌ $A - B = B - A$
   - ✅ $A - B \neq B - A$ (generally)

---

## 🔗 Related Topics

- **Logic:** Set operations correspond to logical operations ($\cup$ ≈ OR, $\cap$ ≈ AND)
- **Probability:** Sample spaces and events are sets
- **Relations:** Binary relations are subsets of Cartesian products
- **Functions:** Special relations where each input maps to exactly one output
- **Topology:** Open sets, closed sets, neighborhoods
- **Abstract Algebra:** Groups, rings, fields are sets with operations

---

## 💡 Practice Tips

1. **Draw Venn diagrams** for visualization
2. **Use element method** when proving set identities
3. **Check special cases:** empty set, universal set, equal sets
4. **Verify with examples** before proving formally
5. **Learn the laws** - they simplify complex expressions
6. **Practice counting** with inclusion-exclusion principle

---

*Quick reference for settheory.md - October 28, 2025*
