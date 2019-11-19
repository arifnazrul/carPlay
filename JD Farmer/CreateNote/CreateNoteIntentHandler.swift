//
//  CreateNoteIntentHandler.swift
//  CreateNote
//
//  Created by Ajdari, Arian on 19.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import Intents


class CreateNoteIntentHandler: NSObject, CreateNoteIntentHandling {
    func resolveCreateNotePrompt(for intent: CreateNoteIntent, with completion: @escaping (Enum1ResolutionResult) -> Void) {
        
        if intent.createNotePrompt == .unknown {
            completion(Enum1ResolutionResult.needsValue())
        } else {
            completion(Enum1ResolutionResult.success(with: intent.createNotePrompt))
        }
    }
    
   
       
    func handle(intent: CreateNoteIntent, completion: @escaping (CreateNoteIntentResponse) -> Void) {
        if intent.createNotePrompt == .yes   {
               let createNoteController = CreateNoteController()
               if(createNoteController.createNote(intent: intent)) {
                   completion(CreateNoteIntentResponse(code: .success, userActivity: nil))
               }
           } else {
            completion(CreateNoteIntentResponse(code: .cancel, userActivity: nil))
           }
       }
       
       func resolveNoteType(for intent: CreateNoteIntent, with completion: @escaping (EnumResolutionResult) -> Void) {
        
           if intent.noteType == .unknown {
               completion(EnumResolutionResult.needsValue())
           } else {
               completion(EnumResolutionResult.success(with: intent.noteType))
           }
           
       }
       
       func resolveContent(for intent: CreateNoteIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
           guard let content = intent.content else {
               completion(INStringResolutionResult.needsValue())
               return
           }
           completion(INStringResolutionResult.success(with: content))
       }
    
    
    
    
    

}



