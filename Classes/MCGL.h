//
//  MCGL.h
//  HelloCone
//
//  Created by Aha on 12-10-24.
//
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <stack>
#import "Matrix.hpp"
#import "Quaternion.hpp"
using namespace std;

#define SWAP_ROWS_DOUBLE(a, b) { double *_tmp = a; (a)=(b); (b)=_tmp; }
#define SWAP_ROWS_FLOAT(a, b) { float *_tmp = a; (a)=(b); (b)=_tmp; }
#define MAT(m,r,c) (m)[(c)*4+(r)]

@interface MCGL : NSObject

+(BOOL)unProjectfWithScreenX:(float)winx
                     screenY:(float)winy
                      depthZ:(float)winz
                returnObject:(float*)object;

//the function like glMatrixMode
+(void)matrixMode:(GLenum)mode;

//the function like glLoadIdentity()
+(void)loadIdentity;

//the function like gluPerspective
+(void)perspectiveWithFovy:(float)fovy
                    aspect:(float)aspect
                     zNear:(float)zNear
                      zFar:(float)zFar;

//the function like glTranslatef
+(void)translateWithX:(float)x
                    Y:(float)y
                    Z:(float)z;

+(void)rotateWithQuaternion:(Quaternion)delta;

//the function like gluLookAt
+(void)lookAtEyefv:(vec3)eye
          centerfv:(vec3)center
              upfv:(vec3)up;

//the function like glPushMatrix
+(void)pushMatrix;

//the function like glPopMatrix
+(void)popMatrix;

//+(mat4)getMatrixWithMatrixMode:(GLenum)matrixMode;

//+(void)getIntegervWithMatrixMode:(GLenum)matrixMode returnMatrix:(GLint *)matrix;

void multiplyMatrices4by4OpenGL_FLOAT(float *result, const const float *matrix1, const float *matrix2);

void multiplyMatrixByVector4by4OpenGL_FLOAT(float *resultvector, const float *matrix, const float *pvector);

int glhInvertMatrixf2(float *m, float *out);

@end
