/*
 
 File: LeDataService.h
 
 Abstract: Data Service Header - Connect to a peripheral
 and send and receive data.
 
 
 */



#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "LeService.h"



/****************************************************************************/
/*								Protocol									*/
/****************************************************************************/
@class LeDataService;

@protocol LeDataProtocol<NSObject>
- (void) serviceDidReceiveData:(NSData*)data fromService:(LeDataService*)service;
- (void) serviceDidReceiveCharacteristicsFromService:(LeDataService*)service;
- (void) didWriteFromService:(LeDataService *)service withError:(NSError *)error;
@end


/****************************************************************************/
/*						Data service.                                       */
/****************************************************************************/
@interface LeDataService : NSObject

- (id) initWithPeripheral:(CBPeripheral *)peripheral delegate:(id<LeDataProtocol>)delegate;
- (void) setDelegate:(id<LeDataProtocol>)delegate;

- (void) reset;
- (void) start;

- (void) write:(NSData *)data;

/* Behave properly when heading into and out of the background */
- (void)enteredBackground;
- (void)enteredForeground;

@property (readonly) CBPeripheral *peripheral;
@end
