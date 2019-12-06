//
//  myDelegate.swift
//  JDAPITest
//
//  Created by Asankozhoev, Talant on 06.12.19.
//  Copyright © 2019 Capstone. All rights reserved.
//

import Foundation

class myDelegate : JDLoginViewControllerDelegate {
    func loginViewControllerDelegateDidFinishLogin(withSuccess sender: JDLoginViewController?, andUser user: JDUser) {
        print("GOOD")
    }
    
    func loginViewControllerDelegateDidFinishLoginWithError(_ error: Error) {
        print("BADDD")
    }
    
    func isEqual(_ object: Any?) -> Bool {
        print("isequl")
    }
    
    var hash: Int
    
    var superclass: AnyClass?
    
    func `self`() -> Self {
        print("eself")
    }
    
    func perform(_ aSelector: Selector!) -> Unmanaged<AnyObject>! {
        print("perfo")
    }
    
    func perform(_ aSelector: Selector!, with object: Any!) -> Unmanaged<AnyObject>! {
        print("perform2")
    }
    
    func perform(_ aSelector: Selector!, with object1: Any!, with object2: Any!) -> Unmanaged<AnyObject>! {
        print("perf3")
    }
    
    func isProxy() -> Bool {
        print("isporx")
    }
    
    func isKind(of aClass: AnyClass) -> Bool {
        print("isKind")
    }
    
    func isMember(of aClass: AnyClass) -> Bool {
        print("ismeber")
    }
    
    func conforms(to aProtocol: Protocol) -> Bool {
        print("conf")
    }
    
    func responds(to aSelector: Selector!) -> Bool {
        print("responf")
    }
    
    var description: String
    
    
}
