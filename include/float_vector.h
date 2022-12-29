# ifndef FLOAT_VECTOR

# define FLOAT_VECTOR

typedef struct float_vector FloatVector;

FloatVector *create(int capacity);

void clear(FloatVector **pFloatVector);

int size(const FloatVector *floatVector);

int capacity(const FloatVector *floatVector);

//float at(const FloatVector *floatVector, int index);
//
//float get(const FloatVector *floatVector, int index);

void append(FloatVector *floatVector, float value);

//void set(const FloatVector *floatVector, int index, float value);

void print(const FloatVector *floatVector);

# endif
