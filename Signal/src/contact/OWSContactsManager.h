#import <Contacts/Contacts.h>
#import <Foundation/Foundation.h>
#import <SignalServiceKit/ContactsManagerProtocol.h>
#import <SignalServiceKit/PhoneNumber.h>
#import "CollapsingFutures.h"
#import "Contact.h"
#import "ObservableValue.h"

NS_ASSUME_NONNULL_BEGIN

@class UIFont;

/**
 * Get latest Signal contacts, and be notified when they change.
 */
@interface OWSContactsManager : NSObject <ContactsManagerProtocol>

@property (nullable, strong) CNContactStore *contactStore;
@property (nonnull, readonly, strong) NSCache<NSString *, UIImage *> *avatarCache;

- (nonnull ObservableValue *)getObservableContacts;

- (nonnull NSArray *)getContactsFromAddressBook:(nonnull ABAddressBookRef)addressBook;
- (nullable Contact *)latestContactForPhoneNumber:(nullable PhoneNumber *)phoneNumber;

- (void)verifyABPermission;

- (NSArray<Contact *> *)allContacts;
- (NSArray<Contact *> *)signalContacts;

- (void)doAfterEnvironmentInitSetup;

- (NSString *)displayNameForPhoneIdentifier:(nullable NSString *)identifier;
- (nullable UIImage *)imageForPhoneIdentifier:(nullable NSString *)identifier;
- (NSAttributedString *)formattedFullNameForContact:(Contact *)contact font:(UIFont *)font;

+ (NSComparator _Nonnull)contactComparator;

@end

NS_ASSUME_NONNULL_END
