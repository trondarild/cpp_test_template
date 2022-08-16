

float* reset_array(float *r, int size);
float sum(float *a, int size);
void print_array(float *a, int size);
float *soft_max_exp(float *r, float *a, int size);
float *soft_max_pw(float *r, float *a, float pw, int size);
float **sequentials(float **retval, float start, int x, int y);
float **transpose(float ** a_T, float ** a, int sizex, int sizey);
void hstack(float **retval, float **a, int ax, float **b, int bx, int rety);