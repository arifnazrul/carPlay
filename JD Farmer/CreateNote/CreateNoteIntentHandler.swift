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
    func resolveDate(for intent: CreateNoteIntent, with completion: @escaping (INStringResolutionResult) -> Void) {
        if intent.createReminderPrompt == .yes {
            guard let date = intent.date else {
                       completion(INStringResolutionResult.needsValue())
                       return
                   }
            completion(INStringResolutionResult.success(with: date))
        }else {
            completion(INStringResolutionResult.success(with: ""))
        }
        
       
    }
    
    
    
    
    
    func resolveCreateReminderPrompt(for intent: CreateNoteIntent, with completion: @escaping (Enum5ResolutionResult) -> Void) {
        if intent.createReminderPrompt == .unknown {
            completion(Enum5ResolutionResult.needsValue())
        } else {
            completion(Enum5ResolutionResult.success(with: intent.createReminderPrompt))
        }
    }
    
    func resolveFieldName(for intent: CreateNoteIntent, with completion: @escaping (Enum2ResolutionResult) -> Void) {
        if intent.noteType == .field {
            if intent.fieldName == .unknown {
                completion(Enum2ResolutionResult.needsValue())
            } else {
                completion(Enum2ResolutionResult.success(with: intent.fieldName))
            }
        }else {
            completion(Enum2ResolutionResult.success(with: intent.fieldName))
        }
    }
    
  
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



