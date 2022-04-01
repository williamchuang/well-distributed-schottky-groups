_qrt(numb[0]*numb[0]+numb[1]*numb[1])

def Cartesian_complex_complex_conjugate(numb):
    return [numb[0],-numb[1]]

def Cartesian_complex_complex_to_polar(numb):
    r=Cartesian_complex_modulus(numb)
    if numb[0]>0:
        t=math.atan(float(numb[1]/numb[0]))
    elif numb[0]<0:
        t=math.atan(float(numb[1]/numb[0]))+math.pi
    else:
        if numb[1]>0:
            t=float(math.pi/2)
        elif numb[1]<0:
            t=float(-math.pi/2)
        else:
            t="null"
    return [r,t]

def Polar_complex_complex_to_Cartesian(numb):
    return [numb[0]*math.cos(numb[1]),numb[0]*math.sin(numb[1])]

def Polar_complex_conjugate(numb):
    return [numb[0],-numb[1]]

def Polar_complex_mul(numb1,numb2):
    #numb1 r_1e^(it_1), [r_1,t_1], numb2 r_2e^(it_2), [r_2,t_2]
    r=numb1[0]*numb2[0]
    t=numb1[1]+numb2[1]
    return [r,t]

def Polar_complex_divide(numb1,numb2):
    #numb1 r_1e^(it_1), [r_1,t_1], numb2 r_2e^(it_2), [r_2,t_2]
    r=float(numb1[0]/numb2[0])
    t=numb1[1]-numb2[1]
    return [r,t]

def Polar_complex_add(numb1,numb2):
    N1=Polar_complex_complex_to_Cartesian(numb1)
    N2=Polar_complex_complex_to_Cartesian(numb2)
    tot=Cartesian_complex_add(N1,N2)
    return Cartesian_complex_complex_to_polar(tot)

def real_matrix_addition(m1,m2):
    #m1=[[M11,M12],[M21,M22]]
    a=m1[0][0]+m2[0][0]
    b=m1[0][1]+m2[0][1]
    c=m1[1][0]+m2[1][0]
    d=m1[1][1]+m2[1][1]
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def Cartesian_complex_matrix_addition(m1,m2):
    #m1=[[M11,M12],[M21,M22]]
    #M11=[a,b]
    a1=m1[0][0][0]+m2[0][0][0]
    a2=m1[0][0][1]+m2[0][0][1]
    b1=m1[0][1][0]+m2[0][1][0]
    b2=m1[0][1][1]+m2[0][1][1]
    c1=m1[1][0][0]+m2[1][0][0]
    c2=m1[1][0][1]+m2[1][0][1]
    d1=m1[1][1][0]+m2[1][1][0]
    d2=m1[1][1][1]+m2[1][1][1]
    a=[a1,a2]
    b=[b1,b2]
    c=[c1,c2]
    d=[d1,d2]
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def real_matrix_multiplication(m1,m2):
    #m1=[[M11,M12],[M21,M22]]
    a=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]
    b=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]
    c=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]
    d=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def Cartesian_complex_matrix_multiplication(m1,m2):
    #m1=[[M11,M12],[M21,M22]]
    #M11=[a,b]
    a=Cartesian_complex_add(Cartesian_complex_mul(m1[0][0],m2[0][0]),Cartesian_complex_mul(m1[0][1],m2[1][0])) 
    b=Cartesian_complex_add(Cartesian_complex_mul(m1[0][0],m2[0][1]),Cartesian_complex_mul(m1[0][1],m2[1][1])) 
    c=Cartesian_complex_add(Cartesian_complex_mul(m1[1][0],m2[0][0]),Cartesian_complex_mul(m1[1][1],m2[1][0])) 
    d=Cartesian_complex_add(Cartesian_complex_mul(m1[1][0],m2[0][1]),Cartesian_complex_mul(m1[1][1],m2[1][1])) 
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def real_matrix_inverse(m1):
    #m1=[[M11,M12],[M21,M22]]
    det=m1[0][0]*m1[1][1]-m1[0][1]*m1[1][0]
    a=float(m1[1][1]/det)
    b=float(-m1[0][1]/det)
    c=float(-m1[1][0]/det)
    d=float(m1[0][0]/det)
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def Cartesian_complex_matrix_inverse(m1):
    #m1=[[M11,M12],[M21,M22]]
    #M11=[a,b]
    det=Cartesian_complex_add(Cartesian_complex_mul(m1[0][0],m1[1][1]),Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(m1[0][1],m1[1][0])))   
    inverse_det=Cartesian_complex_divide([1,0],det)
    a=Cartesian_complex_mul(m1[1][1],inverse_det)
    b=Cartesian_complex_mul(Cartesian_complex_scalar_mul(-1,m1[0][1]),inverse_det) 
    c=Cartesian_complex_mul(Cartesian_complex_scalar_mul(-1,m1[1][0]),inverse_det) 
    d=Cartesian_complex_mul(m1[0][0],inverse_det)
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l


def Cartesian_radial_hyperbolic_distance(z):
    r=float(Cartesian_complex_modulus(z))
    return math.log(float((1+r)/(1-r)))

def operator_T(Lambda):
    D=2
    a1=(-Lambda-float(1/Lambda))*float(-0.5)
    a2=0
    b1=0
    b2=(-Lambda+float(1/Lambda))*float(-0.5)
    c1=0
    c2=(Lambda-float(1/Lambda))*float(-0.5)
    d1=(-Lambda-float(1/Lambda))*float(-0.5)
    d2=0
    l1=[[a1,a2],[b1,b2]]
    l2=[[c1,c2],[d1,d2]]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def operator_R(theta):
    a=Polar_complex_complex_to_Cartesian([1,float(0.5*theta)])
    b=[0,0]
    c=[0,0]
    d=Polar_complex_complex_to_Cartesian([1,float(-0.5*theta)])
    l1=[a,b]
    l2=[c,d]
    l=[]
    l.append(l1)
    l.append(l2)
    return l

def classification_point(Lambda):
    return [float((2*Lambda**2)/(Lambda**4+1)),float((Lambda**4-1)/(Lambda**4+1))]

def check_T_generate_a_Schottky(Lambda,m):
    t=float(-math.pi/2)+float(math.pi/(2*m))
    K=Polar_complex_complex_to_Cartesian([1,t])
    B=classification_point(Lambda)
    T=operator_T(Lambda)
    T0=Cartesian_complex_divide(T[0][1],T[1][1])
    discriminant=float(Cartesian_complex_modulus(Cartesian_complex_add(K,Cartesian_complex_scalar_mul(-1,T0)))**2)-float(Cartesian_complex_modulus(Cartesian_complex_add(B,Cartesian_complex_scalar_mul(-1,T0)))**2) 
    print(discriminant)
    if discriminant>0:
        return True
    else:
        return False

def Tz(T,z):
    a=T[0][0]
    b=T[0][1]
    c=T[1][0]
    d=T[1][1]
    return  Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,z),b),Cartesian_complex_add(Cartesian_complex_mul(c,z),d))




#Generate the orbit Gamma(0)
def Gamma0(Lambda,m,N):
    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    L=[Tz(T,[0,0])]
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    j=1
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    return nodes_in_DT
# measuring hyperbolic distance
def Hyperbolic_Distance_Gamma0(Lambda,m,N):
    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    L=[Tz(T,[0,0])]
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    j=1
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    Hyperbolic_distance=[]
    for k in nodes_in_DT:
        Hyperbolic_distance.append(Cartesian_radial_hyperbolic_distance(k))
    return Hyperbolic_distance

# measuring Exp(-hyperbolic distance)
def Exp_negative_Hyperbolic_Distance_Gamma0(Lambda,m,N):
    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    L=[Tz(T,[0,0])]
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    j=1
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    Hyperbolic_distance=[]
    for k in nodes_in_DT:
        Hyperbolic_distance.append(math.exp(-Cartesian_radial_hyperbolic_distance(k)))
    return Hyperbolic_distance

# measuring Exp(-hyperbolic distance)
def Exp_negative_Hyperbolic_Distance_Gamma0_with_t(Lambda,m,N,t):
    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    L=[Tz(T,[0,0])]
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    j=1
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    Hyperbolic_distance=[]
    for k in nodes_in_DT:
        Hyperbolic_distance.append(math.exp(-t*Cartesian_radial_hyperbolic_distance(k)))
    return Hyperbolic_distance

# measuring Exp(-t*(hyperbolic distance))
def Improved_Exp_negative_Hyperbolic_Distance_Gamma0_with_t(Lambda,m,N,L,t):

    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    if len(L)==0:
        L=[Tz(T,[0,0])]
        j=1
    else:
        j=N
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    Hyperbolic_distance=[]
    for k in nodes_in_DT:
        Hyperbolic_distance.append(math.exp(-t*Cartesian_radial_hyperbolic_distance(k)))
    return [Hyperbolic_distance,L]

# measuring Exp(-hyperbolic distance)
def Improved_Exp_negative_Hyperbolic_Distance_Gamma0(Lambda,m,N,L):

    T=operator_T(Lambda)
    theta=float(math.pi/m)
    R=operator_R(theta)
    if len(L)==0:
        L=[Tz(T,[0,0])]
        j=1
    else:
        j=N
    tmp1=[]
    tmp2=[]
    nodes_in_DT=[[0,0]]
    
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Tz(R,z)
                tmp1.append(z)
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Tz(T,[0,0])]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            for k in L:
                z=Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Tz(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
    Hyperbolic_distance=[]
    for k in nodes_in_DT:
        Hyperbolic_distance.append(math.exp(-Cartesian_radial_hyperbolic_distance(k)))
    return [Hyperbolic_distance,L]



      

# measuring hyperbolic distance
def Gamma(Lambda,m,N):
    
    T=operator_T(Lambda) # T is a 2 by 2 matrix.
    theta=float(math.pi/m)
    ID=[[[1, 0], [0, 0]], [[0, 0], [1, 0]]]
    R=operator_R(theta) # R is a 2 by 2 matrix.
    L=[T]
    tmp1=[]
    tmp2=[]
    model=[]
    component=[]
    
    nodes_in_DT=[ [[[1, 0], [0, 0]], [[0, 0], [1, 0]]]  ]
    j=1
    while j<=N:
        #N=1
        if j==1:
            z=L[0]
            tmp1=[]
            tmp2=[]
            for i in range(2*m-1):
                z=Cartesian_complex_matrix_multiplication(R,z)   #Tz(R,z)
                tmp1.append(z)
                
                if i!=m-1:
                    tmp2.append(z)
                else:
                    tmp2.append(L[0])
            L=[]
            for k in tmp2:
                L.append(k)
            nodes_in_DT=[Cartesian_complex_matrix_multiplication(T,ID)]

        #N>1
        else:
            nodes_in_DT=[]
            tmp1=[]
            tmp2=[]
            tmp3=[]
            
            for k in L:
                z=Cartesian_complex_matrix_multiplication(T,k)       #Tz(T,k)
                nodes_in_DT.append(z)
                tmp1.append(z)
                tmp2.append(z)
                
            
            
            
                    
            
            L=[]
            for i in range(2*m-1):
                if i!=m-1:
                    for k in tmp1:
                        tmp3.append(Cartesian_complex_matrix_multiplication(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                        L.append(k)
                    tmp3=[]
                elif i==m-1:
                    for k in tmp1:
                        tmp3.append(Cartesian_complex_matrix_multiplication(R,k))
                    tmp1=[]
                    for k in tmp3:
                        tmp1.append(k)
                    tmp3=[]
                    for k in tmp2:
                        L.append(k)

        j+=1
        Out=[]  
    index=0
    temp0=[]
    tmp1=[]
    for k in L:
        z=Cartesian_complex_matrix_multiplication(T,k)       #Tz(T,k)
        tmp1.append(z)   
    N=int(math.log(len(tmp1),(2*m-1)))
    print("N:"+str(N))
    initial_index=(((2*m)-1)**(N-1))*(m+1)
    tindex=initial_index
    #print(len(tmp1))
    cindex=0
    counter=0
    for k in tmp1:
        
        if counter==(2*m-1):
            counter=0
            cindex+=1
            
        temp=[]
        component=[]
        component.append(initial_index)
        component.append(cindex)
        initial_index+=1
        initial_index=initial_index%((2*m)*(2*m-1)**(N-1))
        temp.append(k)
        temp.append(component)
        temp0.append(temp)
        counter+=1
    model.append(temp0) 
    initial_index=tindex+(2*m-1)**(N-1)
    initial_index=initial_index%((2*m)*(2*m-1)**(N-1))
    tindex+=1
    tindex=tindex%((2*m)*(2*m-1)**(N-1))
    
    
    temp=[]
    temp1=[]
    temp2=[]
    
    
    print("tmp1"+str(len(tmp1)))
    for i in range(2*m-1):
        
        temp2=[]
        for k in tmp1:
            temp=[]
            temp0=[]
            if counter==(2*m-1):
                counter=0
                cindex+=1
            z=Cartesian_complex_matrix_multiplication(R,k)
            temp2.append(z)
            temp.append(z)
            component=[]
            component.append(initial_index)
            component.append(cindex)
            temp.append(component)
            initial_index+=1
            initial_index=initial_index%((2*m)*(2*m-1)**(N-1))
            temp0.append(temp)

            counter+=1
            model.append(temp0)   
        tmp1=[]
        for k in temp2:
            tmp1.append(k)
        temp2=[]
           
        
        initial_index=tindex+(2*m-1)**(N-1)
        initial_index=initial_index%((2*m)*(2*m-1)**(N-1))
        tindex+=1
        tindex=tindex%((2*m)*(2*m-1)**(N-1))
    #for k in model:
    #    tmp1=[]
    #    component=[]
    #    for key in k:
    #            
    #        print("====")
    #        print(key)
    #    print("------")
            
            
    #Hyperbolic_distance=[]
    #for k in nodes_in_DT:
    #    Hyperbolic_distance.append(Cartesian_radial_hyperbolic_distance(k))
    return model


def non_normalized_derivative(T,z):
    a=T[0][0]
    b=T[0][1]
    c=T[1][0]
    d=T[1][1]
    N=Cartesian_complex_add(Cartesian_complex_mul(a,d),Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(b,c)))
    D=Cartesian_complex_mul(Cartesian_complex_add(Cartesian_complex_mul(c,z),d),Cartesian_complex_add(Cartesian_complex_mul(c,z),d))
    
    if Cartesian_complex_modulus(D)!=0:
        return Cartesian_complex_divide(N,D)
    else:
        return "null"
    
    
def derivatives(model):
    output=[]
    for i in model:
        for j in i:
            tmp=[]
            z=Tz(j[0],[0,-1])
            D_of_T=derivative(j[0],z)
            if D_of_T!="null":
                Tij=float(1/Cartesian_complex_modulus(D_of_T))
            else:
                Tij=0
            tmp.append(Tij)
            tmp.append(j[1])
            output.append(tmp)
    return output
            
# Generate x_j
def Generate_xj(M,x_1):
    #M=number of disks in the first level
    #x_1=[1,0]
    l=[]
    
    k=2
    theta=float(2*math.pi/M)
    mul=Polar_complex_complex_to_Cartesian([1,theta])
    #M=3
    tmp=x_1
    l.append(tmp)
    while k<=M:
        tmp=Cartesian_complex_mul(mul,tmp)
        l.append(tmp)    
        k+=1
    return l
# Compute y_ij
def inverse_f1(R,z,q):
    D=Cartesian_complex_add(z,Cartesian_complex_scalar_mul(-1,q))
    numb2=Cartesian_complex_divide([R**2,0],D)
    return Cartesian_complex_add(Cartesian_complex_complex_conjugate(q),numb2)
def inverse_f2(R,z,q):
    D=Cartesian_complex_add(z,Cartesian_complex_scalar_mul(-1,q))
    numb2=Cartesian_complex_divide([R**2,0],D)
    H2=Cartesian_complex_divide([1,-math.sqrt(3)],[1,math.sqrt(3)])
    H2bar=Cartesian_complex_complex_conjugate(H2)
    return Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_complex_conjugate(q),numb2),H2bar)
def inverse_f3(R,z,q):
    D=Cartesian_complex_add(z,Cartesian_complex_scalar_mul(-1,q))
    numb2=Cartesian_complex_divide([R**2,0],D)
    H3=Cartesian_complex_divide([-1,-math.sqrt(3)],[-1,math.sqrt(3)])
    H3bar=Cartesian_complex_complex_conjugate(H3)
    return Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_complex_conjugate(q),numb2),H3bar)

def Manually_Symmetric_pairs_of_pants(angle,tinitial,incre):
    Theta=angle#math.pi-angle#0.5*angle
    R=math.tan(Theta/2) #math.sqrt(2-2*math.cos(Theta))
    tmpl=Generate_xj(M=3,x_1=[math.sqrt(1+R**2),0])
    tmp2=Generate_xj(M=3,x_1=[1,0])
    
    t11=0
    t22=0
    t33=0
    a=tmpl[0]
    b=Cartesian_complex_add([R**2,0],Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(tmpl[0],
    Cartesian_complex_complex_conjugate(tmpl[0]))))
    c=[1,0]
    d=Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(tmpl[0]))
    T=[[a,b],[c,d]]
    y12=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[1]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[1]),d))
    #to show it's an inverse function
    #print(y12)
    #print(Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,y12),b),
    #                         Cartesian_complex_add(Cartesian_complex_mul(c,y12),d)))
    #print(tmp2[1])
    y13=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[2]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[2]),d))
    t12=float(1/Cartesian_complex_modulus(non_normalized_derivative([[tmpl[0],b],[[1,0],
        Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(tmpl[0]))]],y12)))
    t13=float(1/Cartesian_complex_modulus(non_normalized_derivative([[tmpl[0],b],[[1,0],
        Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(tmpl[0]))]],y13)))
    H2=Cartesian_complex_divide([1,-math.sqrt(3)],[1,math.sqrt(3)])
    H2bar=Cartesian_complex_complex_conjugate(H2)
    q2=tmpl[1]
    a=Cartesian_complex_mul(q2,H2bar)
    b=Cartesian_complex_add([R**2,0],Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(tmpl[1],
    Cartesian_complex_complex_conjugate(tmpl[1]))))
    c=H2bar
    d=Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(q2))
    T=[[a,b],[c,d]]
    y21=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[0]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[0]),d))
    y23=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[2]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[2]),d))
    t21=float(1/Cartesian_complex_modulus(non_normalized_derivative([[a,b],[c,d]],y21)))
    t23=float(1/Cartesian_complex_modulus(non_normalized_derivative([[a,b],[c,d]],y23)))
    H3=Cartesian_complex_divide([-1,-math.sqrt(3)],[-1,math.sqrt(3)])
    H3bar=Cartesian_complex_complex_conjugate(H3)
    q3=tmpl[2]
    a=Cartesian_complex_mul(q3,H3bar)
    b=Cartesian_complex_add([R**2,0],Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(tmpl[2],
    Cartesian_complex_complex_conjugate(tmpl[2]))))
    c=H3bar
    d=Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(q3))
    T=[[a,b],[c,d]]
    y31=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[0]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[0]),d))
    y32=Cartesian_complex_divide(Cartesian_complex_add(Cartesian_complex_mul(a,tmp2[1]),b),
                             Cartesian_complex_add(Cartesian_complex_mul(c,tmp2[1]),d))
    t31=float(1/Cartesian_complex_modulus(non_normalized_derivative([[a,b],[c,d]],y31)))
    t32=float(1/Cartesian_complex_modulus(non_normalized_derivative([[a,b],[c,d]],y32)))
    #print(t11)
    #print(t12)
    #print(t13)
    #print(t21)
    #print(t22)
    #print(t23)
    #print(t31)
    #print(t32)
    #print(t33)
    TIJ=[[t11,t12,t13],[t21,t22,t23],[t31,t32,t33]]
    print(TIJ)
    flag=1
    flag2=0
    while flag==1:
        col=[]
        TIJ_l=[]
        for k in TIJ:
            col=[]
            for i in k:
                val=i**tinitial
                col.append(val)
            TIJ_l.append(col)
        a = np.array(TIJ_l)
        w,v=eig(a)
        M_l=-10000000000
        for k in w:
            if k>M_l:
                M_l=k
        #print(M_l)
        #print("tinitial:"+str(tinitial))
        if M_l>1 and flag2==0:
            flag2=1
        if flag2==1 and M_l<1:
            flag=0
        if M_l<1 and flag2==0:
            flag2=-1
        if flag2==-1 and M_l>1:
            flag=0
        tinitial+=incre
    print("delta:"+str(tinitial))  
    #print("Max eigenvalue:"+str(M_l.real)) 
    return tinitial
def Systematic_Symmetric_pairs_of_pants_first_layer(angle,tinitial,incre):
    z0=[1,0]
    Theta=angle#math.pi-angle#0.5*angle
    R=math.tan(Theta/2) #math.sqrt(2-2*math.cos(Theta))
    tmpl=Generate_xj(M=3,x_1=[math.sqrt(1+R**2),0])
    tmp2=Generate_xj(M=3,x_1=[1,0])
    AB_i=[]
    tmpAB=[]
    for i in range(3):
        if i==0:
            tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,angle/2])))
            tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,((2*math.pi)-angle/2)])))
        else:
            tmpAB.append(Cartesian_complex_mul(AB_i[-1][0],Polar_complex_complex_to_Cartesian([1,angle])))
            tmpAB.append(Cartesian_complex_mul(AB_i[-1][1],Polar_complex_complex_to_Cartesian([1,angle])))
        AB_i.append(tmpAB)
        tmpAB=[]
    
    TIJ=[]
    for i in range(3):
        tmpT=[]
        for j in range(3):
            if i==j:
                tmpT.append(0)
            else:
                yij=func_g(AB_i[i][0],AB_i[i][1],tmp2[j])
                tmpT.append(float(1/Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],yij))))
        TIJ.append(tmpT)
    #TIJ=[[t00,t01,t02],[t10,t11,t12],[t20,t21,t22]]
    print(TIJ)
    flag=1
    flag2=0
    while flag==1:
        col=[]
        TIJ_l=[]
        for k in TIJ:
            col=[]
            for i in k:
                val=i**tinitial
                col.append(val)
            TIJ_l.append(col)
        a = np.array(TIJ_l)
        w,v=eig(a)
        M_l=-10000000000
        for k in w:
            if k>M_l:
                M_l=k
        #print(M_l)
        #print("tinitial:"+str(tinitial))
        if M_l>1 and flag2==0:
            flag2=1
        if flag2==1 and M_l<1:
            flag=0
        if M_l<1 and flag2==0:
            flag2=-1
        if flag2==-1 and M_l>1:
            flag=0
        tinitial+=incre
    print("delta:"+str(tinitial))  
    #print("Max eigenvalue:"+str(M_l.real)) 
    return tinitial
def func(R, q, z):
    qbar=Cartesian_complex_complex_conjugate(q)
    D=Cartesian_complex_add(z,Cartesian_complex_scalar_mul(-1,qbar))
    return Cartesian_complex_add(Cartesian_complex_divide([R**2,0],D),q)
def angle(phi):
    out=float(phi)
    if abs(out)<0.000000000000001:
        return 0
    while out<0:
        out+=2*math.pi
    return out
def Fz(F,z):
    A=F[0][0]
    B=F[0][1]
    C=F[1][0]
    D=F[1][1]
    N=Cartesian_complex_add(Cartesian_complex_mul(A,z),B)
    DD=Cartesian_complex_add(Cartesian_complex_mul(C,z),D)
    return Cartesian_complex_divide(N,DD)

def radius_finder(A,B):
    M=[(A[0]+B[0])/2,(A[1]+B[1])/2]
    PM=Cartesian_complex_complex_to_polar(M)
    a=Cartesian_complex_complex_to_polar(A)
    phi=abs(PM[1]-a[1])
    if phi<(math.pi/2):
        return math.tan(phi)
    else:
        return math.tan(abs(PM[1]+abs(a[1])))

def new_center_finder(A,B):
    RADIUS=radius_finder(A,B)
    M=[(A[0]+B[0])/2,(A[1]+B[1])/2]
    PM=Cartesian_complex_complex_to_polar(M)
    return Polar_complex_complex_to_Cartesian([math.sqrt(1+RADIUS**2), PM[1]])

def input_finder(A,B):
    M=[(A[0]+B[0])/2,(A[1]+B[1])/2]
    PM=Cartesian_complex_complex_to_polar(M)
    return Polar_complex_complex_to_Cartesian([1, PM[1]])

#ax+by=c
#return [a,b,c]
def symetric_axis(A,B):
    if abs(A[0]-B[0])<0.00001:
        return [0,1,0]
    else:
        return [-(A[1]+B[1])/(A[0]+B[0]),1,0]
def func_h(A,B,z):
    SA=symetric_axis(A,B)
    #print("SA"+str(SA))
    a=[SA[0],0]
    b=[1,0]
    K=Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul([0,1],a))
    N=Cartesian_complex_mul(Cartesian_complex_complex_conjugate(z),Cartesian_complex_add(b,K))
    D=Cartesian_complex_add(b,Cartesian_complex_mul([0,1],a))
    return Cartesian_complex_divide(N,D)
def func_I(A,B,z):
    Radius=radius_finder(A,B)
    #print("Radius"+str(Radius))
    NEW_CENTER=new_center_finder(A,B)
    #print("NEW_CENTER"+str(NEW_CENTER))
    K1=Cartesian_complex_complex_conjugate(Cartesian_complex_add(z,Cartesian_complex_scalar_mul(-1,NEW_CENTER)))
    #print("z"+str(z))
    #print("Cartesian_complex_scalar_mul(-1,NEW_CENTER)"+str(Cartesian_complex_scalar_mul(-1,NEW_CENTER)))
    K2=Cartesian_complex_divide([Radius**2,0],K1)
    return Cartesian_complex_add(K2,NEW_CENTER)
def func_g(A,B,z):
    z=func_h(A,B,z)
    return func_I(A,B,z)

def generator(A,B):
    R=radius_finder(A,B)
    q=new_center_finder(A,B)
    SA=symetric_axis(A,B)
    a=[SA[0],0]
    b=[SA[1],0]
    H=Cartesian_complex_divide(Cartesian_complex_add(b,Cartesian_complex_mul([0,1],Cartesian_complex_scalar_mul(-1,a))),Cartesian_complex_add(b,Cartesian_complex_mul([0,1],a)))
    A=Cartesian_complex_mul(q,Cartesian_complex_complex_conjugate(H))
    #print("A:"+str(A))
    B=Cartesian_complex_add([R**2,0],Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(q,Cartesian_complex_complex_conjugate(q))))
    #print("B:"+str(B))
    C=Cartesian_complex_complex_conjugate(H)
    #print("C:"+str(C))
    D=Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(q))
    #print("D:"+str(D))
    return [[A,B],[C,D]]
def func_g_prime(A,B,z):
    #print("z:"+str(z))
    R=radius_finder(A,B)
    #print("R:"+str(R))
    q=new_center_finder(A,B)
    SA=symetric_axis(A,B)
    a=[SA[0],0]
    b=[SA[1],0]
    H=Cartesian_complex_divide(Cartesian_complex_add(b,Cartesian_complex_mul([0,1],Cartesian_complex_scalar_mul(-1,a))),Cartesian_complex_add(b,Cartesian_complex_mul([0,1],a)))
    A=Cartesian_complex_mul(q,Cartesian_complex_complex_conjugate(H))
    #print("A:"+str(A))
    B=Cartesian_complex_add([R**2,0],Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(q,Cartesian_complex_complex_conjugate(q))))
    #print("B:"+str(B))
    C=Cartesian_complex_complex_conjugate(H)
    #print("C:"+str(C))
    D=Cartesian_complex_scalar_mul(-1,Cartesian_complex_complex_conjugate(q))
    #print("D:"+str(D))
    N=Cartesian_complex_add(Cartesian_complex_mul(A,D),Cartesian_complex_scalar_mul(-1,Cartesian_complex_mul(B,C)))
    d=Cartesian_complex_add(Cartesian_complex_mul(C,z),D)
    DD=Cartesian_complex_mul(d,d)
    #print("DD:"+str(DD))
    #print("N:"+str(N))
    #print("Cartesian_complex_modulus(N):"+str(Cartesian_complex_modulus(N)))
    #print("Cartesian_complex_modulus(DD):"+str(Cartesian_complex_modulus(DD)))
    return(Cartesian_complex_divide(N,DD))
def find_delta(TIJ,tinitial,incre):
    flag=1
    flag2=0
    while flag==1:
        col=[]
        TIJ_l=[]
        for k in TIJ:
            col=[]
            for i in k:
                val=i**tinitial
                col.append(val)
            TIJ_l.append(col)
        a = np.array(TIJ_l)
        w,v=eig(a)
        M_l=-10000000000
        for k in w:
            if k>M_l:
                M_l=k
        #print(M_l)
        #print("tinitial:"+str(tinitial))
        if M_l>1 and flag2==0:
            flag2=1
        if flag2==1 and M_l<1:
            flag=0
        if M_l<1 and flag2==0:
            flag2=-1
        if flag2==-1 and M_l>1:
            flag=0
        tinitial+=incre
    print("delta:"+str(tinitial))
    return tinitial
def Check_AB_i_Initial(A, B,INITIAL, j):
    a=Cartesian_complex_complex_to_polar(A)
    b=Cartesian_complex_complex_to_polar(B)
    
    if j==0:
        testpt=input_finder(A,B)
        t=Cartesian_complex_complex_to_polar(testpt)
        aa=Cartesian_complex_complex_to_polar(INITIAL[0][0])
        bb=Cartesian_complex_complex_to_polar(INITIAL[0][1])
        if (t[1]>0 and aa[1]>0 and t[1]<aa[1]) or (t[1]<0 and aa[1]<0 and t[1]>aa[1]):
            #print("a[1]:"+str(a[1]))
            #print("t[1]:"+str(t[1]))
            return False
        if (t[1]>0 and bb[1]>0 and t[1]<bb[1]) or (t[1]<0 and bb[1]<0 and t[1]>bb[1]):
            return False
        else:
            return True
    if j==1:
        if (a[1]>=math.pi/3+0.00000000001 and a[1]<=math.pi-0.00000000001) or (b[1]>=math.pi/3+0.00000000001 and b[1]<=math.pi-0.00000000001):
            return False
        else:
            return True
    if j==2:
        if (a[1]>=-math.pi+0.00000000001 and a[1]<=-math.pi/3-0.00000000001) or (b[1]>=-math.pi+0.00000000001 and b[1]<=-math.pi/3-0.00000000001):
            return False
        elif (a[1]>=math.pi+0.00000000001 and a[1]<=math.pi*5/3-0.00000000001) or (b[1]>=math.pi+0.00000000001 and b[1]<=math.pi*5/3-0.00000000001):
            return False
        else:
            return True

def N_level_Symmetric_pairs_of_pants_Geometric_Method(angle,tinitial,incre,NoL):
    z0=[1,0]
    R=math.tan(angle/2) #math.sqrt(2-2*math.cos(Theta))
    tmpl=Generate_xj(M=3,x_1=[math.sqrt(1+R**2),0])
    tmp2=Generate_xj(M=3,x_1=[1,0])
    k=1
    R=[]
    AB_i=[]
    AB_j=[]
    tmpAB=[]
    DELTA=[]
    INITIAL=[]
    while k<=NoL:
        if k==1:
            #find the first level ABs
            for i in range(3):
                if i==0:
                    tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,angle/2])))
                    tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,((2*math.pi)-angle/2)])))
                else:
                    tmpAB.append(Cartesian_complex_mul(AB_i[-1][0],Polar_complex_complex_to_Cartesian([1,angle])))
                    tmpAB.append(Cartesian_complex_mul(AB_i[-1][1],Polar_complex_complex_to_Cartesian([1,angle])))
                AB_i.append(tmpAB)
                tmpAB=[]
                
            #keep the initial
            for ii in AB_i:
                INITIAL.append(ii)
            print(INITIAL)    
            #assemble Tij
            TIJ=[]
            for i in range(len(AB_i)):
                tmpT=[]
                for j in range(len(AB_i)):
                    if i==j:
                        tmpT.append(0)
                    else:
                        yij=func_g(AB_i[i][0],AB_i[i][1],tmp2[j])
                        #tmpT.append(float(1/Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],yij))))
                        tmpT.append(float(Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],tmp2[j]))))
                
                TIJ.append(tmpT)
            #TIJ=[[t00,t01,t02],[t10,t11,t12],[t20,t21,t22]]
            print(TIJ)
            
            #find delta
            DELTA.append([k,find_delta(TIJ,tinitial,incre)])
            print("level:"+str(k))
            print("delta:"+str(DELTA[-1]))   
            
            #Create the next level ABs
            AB_j=[]
            tmpAB=[]
            i=0
            for ii in AB_i:
                j=0
                while j<len(AB_i):
                    if j!=i:
                        tmpAB.append(func_g(ii[0],ii[1],AB_i[j][0]))
                        tmpAB.append(func_g(ii[0],ii[1],AB_i[j][1]))
                        AB_j.append(tmpAB)
                    tmpAB=[]
                    j+=1          
                i+=1
            i=0
            j=0
            tmpAB=[]
            AB_i=[]
            for ii in AB_j:
                AB_i.append(ii)
            AB_j=[]
            
                 
        else:
            #assemble Tij
            TIJ=[]
            for i in range(len(AB_i)):
                tmpT=[]
                for j in range(len(AB_i)):
                    if i==j:
                        tmpT.append(0)
                    else:
                        #print("i:"+str(i))
                        #print("j:"+str(j))
                        #print("AB_i[i][0]:"+str(AB_i[i][0]))
                        #print("AB_i[i][1]:"+str(AB_i[i][1]))
                        #print("AB_i[j][0]:"+str(AB_i[j][0]))
                        #print("AB_i[j][1]:"+str(AB_i[j][1]))
                        #print("input_finder(AB_i[j][0],AB_i[j][1]):"+str(input_finder(AB_i[j][0],AB_i[j][1])))
                        yij=func_g(AB_i[i][0],AB_i[i][1],input_finder(AB_i[j][0],AB_i[j][1]))
                        #print("yij:"+str(yij))
                        tmpT.append(float(1/Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],yij))))
                        
                        if float(1/Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],yij)))>1:
                            print("########")
                TIJ.append(tmpT)
            #TIJ=[[t00,t01,t02],[t10,t11,t12],[t20,t21,t22]]
            print(TIJ)
            #find delta
            DELTA.append([k,find_delta(TIJ,tinitial,incre)])
            print("level:"+str(k))
            print("delta:"+str(DELTA[-1]))   
            print(k)
            
            #Create the next level ABs
            AB_j=[]
            tmpAB=[]
            i=0
            #print("len(AB_i):"+str(len(AB_i)))
            #print("len(INITIAL):"+str(len(INITIAL)))
            for ii in AB_i:
                j=0
                while j<len(INITIAL):
                    #print("INITIAL[j]:"+str(INITIAL[j]))
                    #print("ii:"+str(ii))
                    if Check_AB_i_Initial(ii[0], ii[1],INITIAL, j):
                        #print("True")
                        tmpAB.append(func_g(ii[0],ii[1],INITIAL[j][0]))
                        tmpAB.append(func_g(ii[0],ii[1],INITIAL[j][1]))
                        AB_j.append(tmpAB)
                    tmpAB=[]
                    j+=1          
                i+=1
            i=0
            j=0
            tmpAB=[]
            AB_i=[]
            for ii in AB_j:
                AB_i.append(ii)
            AB_j=[]
            #print(len(AB_i))
        k+=1   
        
def N_level_Symmetric_pairs_of_pants_Matrix_Method(angle,tinitial,incre,NoL):
    z0=[1,0]
    R=math.tan(angle/2) #math.sqrt(2-2*math.cos(Theta))
    tmpl=Generate_xj(M=3,x_1=[math.sqrt(1+R**2),0])
    tmp2=Generate_xj(M=3,x_1=[1,0])
    k=1
    R=[]
    AB_i=[]
    AB_j=[]
    tmpAB=[]
    DELTA=[]
    INITIAL=[]
    GEN=[]
    while k<=NoL:
        if k==1:
            #find the first level ABs
            for i in range(3):
                if i==0:
                    tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,angle/2])))
                    tmpAB.append(Cartesian_complex_mul(z0,Polar_complex_complex_to_Cartesian([1,((2*math.pi)-angle/2)])))
                else:
                    tmpAB.append(Cartesian_complex_mul(AB_i[-1][0],Polar_complex_complex_to_Cartesian([1,angle])))
                    tmpAB.append(Cartesian_complex_mul(AB_i[-1][1],Polar_complex_complex_to_Cartesian([1,angle])))
                AB_i.append(tmpAB)
                tmpAB=[]
                
            #generate and keep the initial generators
            
            
            for ii in AB_i:
                INITIAL.append(generator(ii[0],ii[1]))
            #print(Cartesian_complex_matrix_multiplication(INITIAL[0],INITIAL[1]))   
            #assemble Tij
            TIJ=[]
            for i in range(len(AB_i)):
                tmpT=[]
                for j in range(len(AB_i)):
                    if i==j:
                        tmpT.append(0)
                    else:
                        yij=func_g(AB_i[i][0],AB_i[i][1],tmp2[j])
                        #tmpT.append(float(1/Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],yij))))
                        tmpT.append(float(Cartesian_complex_modulus(func_g_prime(AB_i[i][0],AB_i[i][1],tmp2[j]))))
                
                TIJ.append(tmpT)
            #TIJ=[[t00,t01,t02],[t10,t11,t12],[t20,t21,t22]]
            print(TIJ)
            
            #find delta
            DELTA.append([k,find_delta(TIJ,tinitial,incre)])
            print("level:"+str(k))
            print("delta:"+str(DELTA[-1]))   
      
            #Create the next level operators
            
            tmpAB=[]
            index=[]
            
            
            for i in range(len(INITIAL)):
                j=0
                while j<len(INITIAL):
                    if j!=i:
                        tmpAB.append(Cartesian_complex_matrix_multiplication(INITIAL[i],INITIAL[j]))
                        #index.append(str(i)+str(j))
                        tmpAB.append(str(i)+str(j))
                        GEN.append(tmpAB)
                        
                    tmpAB=[]
                    index=[]
                    j+=1          
                
            i=0
            j=0
            tmpAB=[]
             
        else:
            
            mdict={}
            j=0
            #print(GEN)
            for ii in GEN:
                #print(ii[1])
                mdict[ii[1]] = j
                j+=1
            #print(mdict)
            inv_map = {v: k for k, v in mdict.items()}
            #print("inv_map:"+str(inv_map))
            #assemble Tij
            #print("INITIAL:")
            #print(INITIAL)
            #print("GEN:"+str(GEN))
            TIJ=[]
            #for ii in GEN:
            #    print("GEN:"+str(ii[1]))
            for i in range(len(GEN)):
                tmpT=[]
                #print("inv_map[i]:"+str(inv_map[i]))
                key=inv_map[i][1:]

                #print("key:"+str(key))
                #print("inv_map[i]:"+str(inv_map[i]))
                for j in range(len(GEN)):
                    lock=inv_map[j][:-1]
                    
                    #print("lock:"+str(lock))
                    if i==j or key!=lock:
                        tmpT.append(0)
                    else:
                        y=tmp2[int(GEN[j][1][-1])]
                        #print("y:"+str(y))
                        #print("+++++++++++++++++++++++++")
                        
                        II=[[[1,0],[0,0]],[[0,0],[1,0]]]
                        JJ=[[[1,0],[0,0]],[[0,0],[1,0]]]
                        for kk in lock:
                            II=Cartesian_complex_matrix_multiplication(II,INITIAL[int(kk)])
                            #print("+++++++++++++++++++++++++")
                            #print("kk:"+str(kk))
                            #print("int(GEN[j][1][-1]):"+str(int(GEN[j][1][-1])))
                            #print("Fz(INITIAL[int(kk)],y):"+str(Fz(INITIAL[int(kk)],y)))

                        for kk in inv_map[i][:-(k-1)]:
                            JJ=Cartesian_complex_matrix_multiplication(JJ,INITIAL[int(kk)])
                            
                        yij=Fz(II,y)
                        #print("yij:"+str(yij))
                        #print(i)
                        #print("Fz(JJ,yij):"+str(Fz(JJ,yij)))
                        #print("Fz(INITIAL["+str(inv_map[i][-1])+"][0],yij):"+str(Fz(INITIAL[int(inv_map[i][-1])],yij)))
                        #print("Fz(INITIAL["+str(inv_map[i][-2])+"][0],yij):"+str(Fz(INITIAL[int(inv_map[i][-2])],Fz(INITIAL[int(inv_map[i][-1])],yij))))
                        #print("len(GEN):"+str(len(GEN)))
                        tmpT.append(float(Cartesian_complex_modulus(non_normalized_derivative(JJ,yij))))
                TIJ.append(tmpT)
            
            #TIJ=[[t00,t01,t02],[t10,t11,t12],[t20,t21,t22]]
            print(TIJ)
            #find delta
            DELTA.append([k,find_delta(TIJ,tinitial,incre)])
            print("level:"+str(k))
            print("delta:"+str(DELTA[-1]))   
            print(k)
            
            #Create the next level reflections
            reflections=[]
            tmpAB=[]
            
            #print("len(AB_i):"+str(len(AB_i)))
            #print("len(INITIAL):"+str(len(INITIAL)))
            i=0
            while i<len(GEN):
                key=int(GEN[i][1][-1])
                #print(GEN[j])
                j=0
                while j<len(INITIAL):
                    if j!=key:
                        tmpAB=[]
                        wirdindex=GEN[i][1]
                        tmpAB.append(Cartesian_complex_matrix_multiplication(GEN[i][0],INITIAL[j]))
                        #print("GEN[i][1]:"+str(GEN[i][1]))
                        wirdindex+=str(j)
                        tmpAB.append(wirdindex)
                        #print(tmpAB)
                        reflections.append(tmpAB)
                        
                    j+=1
                    
                i+=1 
            
            i=0
            j=0
            #print("len(reflections):"+str(len(reflections)))
            #for kk in reflections:
            #    print("-----")
            #    print(kk)
            tmpAB=[]
            GEN=[]
            for ii in reflections:
                GEN.append(ii)
            reflections=[]
            
        k+=1
    #print(DELTA)
    return DELTA


def Sequential_angles_and_levels_of_symmetric_pairs_of_pants_Matrix_Method(angle_downlmt,angle_uplmt,incre,NoL):
    mlist=[]
    tinitial=0.000
    for ele in range(NoL):
        tmp=[]
        mlist.append(tmp)
    print(angle_downlmt)
    for angle in range(angle_downlmt,angle_uplmt):
        print("angle:"+str(angle))
        Angle=float(angle/180)*math.pi
        DELTA=N_level_Symmetric_pairs_of_pants_Matrix_Method(Angle,tinitial,incre,NoL)
        Layer=0
        print(DELTA)
        while Layer<len(mlist):
            mlist[Layer].append(DELTA[Layer][1])
            Layer+=1
    Layer=0
    print(mlist)
    while Layer<len(mlist):
        Xlist=[]
        angle=angle_downlmt
        for k in mlist[Layer]:
            Xlist.append(angle)
            angle+=1
        plt.plot(Xlist, mlist[Layer])
        plt.xlabel("Angle")
        plt.ylabel("Delta")
        #plt.legend()
        plt.title("Layer #="+str(Layer))
        plt.show()
        Layer+=1

#Examples
Sequential_angles_and_levels_of_symmetric_pairs_of_pants_Matrix_Method(angle_downlmt=1,angle_uplmt=121,incre=0.00001,NoL=5)
