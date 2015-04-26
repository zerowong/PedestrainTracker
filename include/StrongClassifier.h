/********************************************************
 StrongClassifier class.
 Use ClassSelector to build a strong classifier.
 Author: Zhengrong Wang.

 Notice: The feature extractor should be prepared
 (if there are any preprocess procedure), the caller
 of strong classifier should do that.

 ********************************************************/

#ifndef STRONG_CLASSIFIER_HEADER
#define STRONG_CLASSIFIER_HEADER

#include "ClassifierSelector.h"

class StrongClassifier {
public:
	StrongClassifier(int numSelector, int numWeakClassifier, 
		const Size &patchSize, bool useFeatureReplace = false, int numBackup = 0);
	virtual ~StrongClassifier();

	// Evaluate a region.
	virtual float Evaluate(const IntegralImage *intImage, const Rect &roi) const;

	// Update the strong classifier.
	virtual bool Update(const IntegralImage *intImage, const Rect &roi, 
		int target, float importance = 1.0f);

protected:
	int numSelector;
	int totalWeakClassifiers;

	ClassifierSelector **selectors;

	Size patchSize;

	// The weight of each selector.
	float *alpha;

	// Whether we replace the weakest classifier in trainging.
	bool useFeatureReplace;

};


#endif