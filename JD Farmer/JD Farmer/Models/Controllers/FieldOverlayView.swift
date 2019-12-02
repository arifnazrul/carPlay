//
//  FieldOverlayView.swift
//  JD Driver
//
//  Created by Ajdari, Arian on 21.11.19.
//  Copyright © 2019 Ajdari, Arian. All rights reserved.
//

import Foundation
import MapKit

class FieldOverlayView: MKOverlayRenderer {
  var overlayImage: UIImage
  
  init(overlay:MKOverlay, overlayImage:UIImage) {
    self.overlayImage = overlayImage
    super.init(overlay: overlay)
  }
  
  override func draw(_ mapRect: MKMapRect, zoomScale: MKZoomScale, in context: CGContext) {
//    guard let imageReference = overlayImage.cgImage else { return }
//
//    let rect = self.rect(for: overlay.boundingMapRect)
//    context.scaleBy(x: 1.0, y: -1.0)
//    context.translateBy(x: 0.0, y: -rect.size.height)
//    context.draw(imageReference, in: rect)
  }
}
