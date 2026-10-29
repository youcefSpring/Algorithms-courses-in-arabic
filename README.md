<div dir="rtl">

# مقياس أساسيات الخوارزميات ولغة C (باللغة العربية)

عروض تقديمية (Beamer) مكتوبة بـ LaTeX باللغة العربية، بنفس قالب مقياس
الذكاء الاصطناعي، مع أمثلة برمجية بلغة C.

الأستاذ: د. بن عبد الرزاق يوسف

## محتوى المقياس

| الفصل | الموضوع | العرض |
|:---:|---|---|
| 1 | مدخل إلى الخوارزميات: المتغيرات، الثوابت، العمليات، القراءة والكتابة | `slides/dars1_slides.pdf` |
| 2 | البنيات الشرطية: `if` و`else if` و`switch` | `slides/dars2_slides.pdf` |
| 3 | الحلقات التكرارية: `for` و`while` و`do while` | `slides/dars3_slides.pdf` |
| 4 | الجداول أحادية البعد | `slides/dars4_slides.pdf` |
| 5 | الجداول ثنائية البعد (المصفوفات) | `slides/dars5_slides.pdf` |
| 6 | السلاسل النصية و`string.h` | `slides/dars6_slides.pdf` |
| 7 | الدوال: المعاملات، القيمة المعادة، التمرير بالقيمة | `slides/dars7_slides.pdf` |
| 8 | العودية | `slides/dars8_slides.pdf` |
| 9 | الهياكل `struct` و`typedef` | `slides/dars9_slides.pdf` |
| 10 | المؤشرات والحجز الديناميكي `malloc` | `slides/dars10_slides.pdf` |
| 11 | الملفات: `fopen`، `fprintf`، `fscanf`، `fgets` | `slides/dars11_slides.pdf` |
| 12 | القوائم المتصلة | `slides/dars12_slides.pdf` |
| 13 | الأشجار الثنائية وشجرة البحث الثنائية | `slides/dars13_slides.pdf` |

يحتوي كل عرض على عشرة أمثلة تطبيقية من مجالات مختلفة
(الصحة، الرياضة، الطقس، النقل، التجارة الإلكترونية، الألعاب، الطاقة، البيئة، …).
كل مثال برنامج كامل مستقل، دون ملفات مساعدة.

## هيكل المستودع

- `slides/` : العروض التقديمية بصيغة PDF.
- `slides/tex/` : مصادر العروض، مع ملف التنسيق المشترك `style.tex`.
- `slides/code/dN/` : برامج C لكل فصل (`.c`) ونتائج تنفيذها الفعلية (`.out`).
- `fonts/` : الخطوط المستعملة (Amiri و AlBattar).

## الترجمة (Compilation)

```bash
cd slides/tex && tectonic -o .. dars1_slides.tex
```

كل البرامج الكاملة قابلة للترجمة:

```bash
gcc -Wall slides/code/d1/ex01.c -o ex01 -lm && ./ex01
```

</div>
# Algorithms-courses-in-arabic
