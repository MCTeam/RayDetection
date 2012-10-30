//
//  MCRay.h
//  HelloCone
//
//  Created by Aha on 12-10-24.
//
//

#import <Foundation/Foundation.h>
#import "Vector.hpp"
#import "MCGL.h"

@interface MCRay : NSObject{
    vec3 vOrigin;
    vec3 vDirection;
}

@property() vec3 vOrigin;
@property() vec3 vDirection;

-(void)updateWithScreenX:(float) screenX
                 screenY:(float) screenY;

-(GLfloat)intersectWithTriangleMadeUpOfV0:(float *)V0
                                    V1:(float *)V1
                                    V2:(float *)V2;

@end
