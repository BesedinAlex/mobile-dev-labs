//---------------------------------------------------------------------------

#pragma hdrstop

#include "Concentration.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Concentration::Concentration(int numberOfPairsOfCards)
{
    for (int i = 0; i < numberOfPairsOfCards; i++)
    {
        auto card = new Card();
		Concentration::cards.push_back(*card);
        Concentration::cards.push_back(*card);
    }
    std::vector<Card> tempCards;
	for (int i = 0; Concentration::cards.size; i++)
	{
		int randomIndex = std::rand();
        auto card = Concentration::cards[randomIndex];
//		Concentration::cards.erase(&card);
		tempCards.push_back(card);
	}
    Concentration::cards = tempCards;
}

//struct Concentration {
//	private(set) var cards = [Card]()
//	private var indexOfOneAndOnlyFaceUpCard: Int? {
//		get {
//			return cards.indices.filter { cards[$0].isFaceUp }.oneAndOnly
//		}
//		set {
//			for index in cards.indices {
//				cards[index].isFaceUp = (index == newValue)
//			}
//		}
//	}
//	mutating func chooseCard(at index: Int) {
//		assert(cards.indices.contains(index), "Concentration.chooseCard(at: \(index)): there's no such card.")
//		if !cards[index].isMatched {
//			if let matchIndex = indexOfOneAndOnlyFaceUpCard, matchIndex != index {
//				if cards[matchIndex] == cards[index] {
//					cards[matchIndex].isMatched = true
//					cards[index].isMatched = true
//				}
//                cards[index].isFaceUp = true
//            } else {
//                indexOfOneAndOnlyFaceUpCard = index
//            }
//        }
//    }
//    init(numberOfPairsOfCards: Int) {
//        assert(numberOfPairsOfCards > 0, "Concentration.init(numberOfPairsOfCards: \(numberOfPairsOfCards)): you must have at least one card.")
//        for _ in 1...numberOfPairsOfCards {
//            let card = Card()
//            cards += [card, card]
//        }
//        var tempCards = [Card]()
//        for _ in cards.indices {
//            let randomIndex = Int(arc4random_uniform(UInt32(cards.count)))
//            let card = cards[randomIndex]
//			cards.remove(at: randomIndex)
//			tempCards.append(card)
//        }
//		cards = tempCards
//    }
//}
//
//extension Collection {
//    var oneAndOnly: Element? {
//        return count == 1 ? first : nil
//	}
// }