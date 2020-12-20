# Vectors

A vector is an entity that has a magnitude and a direction. We use a Cartesian coordinate system to represent it using two components, *x* and *y*, in a 2-dimensional space, or three components, *x*, *y*, and *z*, in a 3-dimensional space.</br></br>

![vector 2d](./images/vector2d.png "vector 2d") [1](https://uploads.toptal.io/blog/image/781/toptal-blog-image-1421917486683.png)

</br></br>


![vector 3d](./images/vector3d.png "vector 3d") [2](https://uploads.toptal.io/blog/image/782/toptal-blog-image-1421917499528.png)

</br></br>

We will represent a vector with a bold lowercase character, and its components with a regular subscripted character. For example: </br>

<div align="center"> <strong>a</strong> = (a<sub>x</sub>, a<sub>y</sub>)</div></br>

represents a 2-dimensional vector. Each component is the distance from the origin in the corresponding coordinate axis.</br></br>

## Length (aka magnitude)

The length, or magnitude, operator is represented by || ||. The Pythagorean theorem for right triangles is use to compute the length from its components. For example, in 2 dimensions:

<div align="center">||a|| = sqrt(a<sub>x</sub><sup>2</sup> + a<sub>y</sub><sup>2</sup>)</div></br></br>

## Negation

When a vector is negated, the length remains the same, but the direction changes to the exact opposite. For example, given

<div align="center"> <strong>a</strong> = (a<sub>x</sub>, a<sub>y</sub>)</div></br>

the negation is</br></br>
<div align="center"> <strong>-a</strong> = (-a<sub>x</sub>, -a<sub>y</sub>)</div></br>


![negation](./images/negate_vector.png "negate vector") [3](https://uploads.toptal.io/blog/image/787/toptal-blog-image-1421917686471.png)</br></br></br>


## Addition and Subtraction

Vectors can be added to each other, or one vector can be subtracted from another. Subtracting two vectors is the same as adding one to the negation of the other. These operations simply add or subtract each component.

**a** + **b** = (a<sub>x</sub>, a<sub>y</sub>) + (b<sub>x</sub>, b<sub>y</sub>) = ((a<sub>x</sub> + b<sub>x</sub>, a<sub>y</sub> + b<sub>y</sub>))</br>

**a** - **b** = (a<sub>x</sub>, a<sub>y</sub>) - (b<sub>x</sub>, b<sub>y</sub>) = ((a<sub>x</sub> - b<sub>x</sub>, a<sub>y</sub> - b<sub>y</sub>))</br>

The resulting vector can be visualized as pointing to the same point that the two original vectors would point if they were connected tip to tail.</br></br>

![addition](./images/addition.png "vector addition") [4](https://uploads.toptal.io/blog/image/789/toptal-blog-image-1421917713199.png)</br></br></br>


## Scalar Multiplication

A vector's length is changed when it is multiplied by a scalar real number. If the scalar is negative, the resulting vector will point in the opposite direction.

<div align="center"> <strong>a</strong>s = (a<sub>x</sub> s, a<sub>y</sub> s)</div></br></br>

![scalar](./images/scalar.gif "scalar multiplication") [5](https://uploads.toptal.io/blog/image/791/toptal-blog-image-1421917737475.gif)</br></br>

## Dot Product

The dot product of two vectors is defined as

<div align="center"> <strong>a</strong> . <strong>b</strong> = ||<strong>a</strong>|| ||<strong>b</strong>|| cos &theta;</div></br>

where &theta; is the angle between the two vectors. The dot product may be computed using the vector components.

<div align="center"> <strong>a</strong> . <strong>b</strong> = a<sub>x</sub>  b<sub>x</sub> + a<sub>y</sub> b<sub>y</sub></div></br></br>

The value of the dot product is equivalent to the length of the projection of vector **a** onto the vector **b**, multiplied by the length of b. The projection of b onto produces the same scalar result. The dot product is commutative.</br></br>

## Cross Product

In three dimensions, we can multiply two vectors to produce an output vector that is orthogonal to the two input vectors.

<div align="center"> <strong>a</strong> x <strong>b</strong> = (a<sub>y</sub>  b<sub>z</sub> - a<sub>z</sub> b<sub>y</sub>, a<sub>z</sub>  b<sub>x</sub> - a<sub>x</sub> b<sub>z</sub>, a<sub>x</sub>  b<sub>y</sub> - a<sub>y</sub> b<sub>x</sub></div></br></br>

The cross product length is

<div align="center"> ||<strong>a</strong> x <strong>b</strong>|| = ||<strong>a</strong>|| ||<strong>b</strong>|| sin &phi;</div></br>

where &phi; is the smallest angle between **a** and **b**.</br>

The cross product is not commutative.</br>

<div align="center"> <strong>a</strong> x <strong>b</strong> = <strong>-b</strong> x <strong>a</strong></div></br>
